#include <fmt/color.h>
#include <fmt/core.h>
#include <fmt/ostream.h>
#include <tlog.h>

#include <cstdio>
#include <fstream>
#include <ios>
#include <memory>
#include <numeric>
#include <string>
#include <string_view>

namespace tlog {

static const std::string INFO_PREFIX = "[INFO]";
// rgb(255, 255, 0): yellow
static const std::string DEBUG_PREFIX =
    fmt::format(fg(fmt::rgb(255, 255, 0)), "[DEBUG]");
// rgb(0, 255, 255): blue
static const std::string WARNNING_PREFIX =
    fmt::format(fg(fmt::rgb(0, 255, 255)), "[WARNNING]");
// rgb(255, 0, 0): red
static const std::string ERROR_PREFIX =
    fmt::format(fg(fmt::rgb(255, 0, 0)), "[ERROR]");
// rgb(0, 255, 0): green
static const std::string SUCCESS_PREFIX =
    fmt::format(fg(fmt::rgb(0, 255, 0)), "[SUCCESS]");

auto tprint(std::initializer_list<std::string_view> src, tlog_status status,
            const std::pair<bool, std::string_view>& wf) -> void {
    if (src.size() == 0) {
        return;
    }
    const std::string *prefix;
    std::string val;

    for (auto str : src){
        val += str;
    }

    switch (status) {
        case INFO:
            prefix = &INFO_PREFIX;
            break;
        case DEBUG:
            prefix = &DEBUG_PREFIX;
            break;
        case WARNNING:
            prefix = &WARNNING_PREFIX;
            break;
        case ERROR:
            prefix = &ERROR_PREFIX;
            break;
        case SUCCESS:
            prefix = &SUCCESS_PREFIX;
            break;
    }

    const std::string message = fmt::format("{} {}\n", *prefix, val);

    if (status == tlog_status::ERROR || status == tlog_status::WARNNING) {
        fmt::print(stderr, "{}", message);
    } else {
        fmt::print(stdout, "{}", message);
    }

    if (!wf.first) {
        return;
    }

    std::string path;
    if (wf.second.empty()) {
        path = "/tmp/filebridge.log";
    } else {
        path = wf.second;
    }

    std::ofstream wfile{path, std::ios::binary | std::ios::app};
    fmt::print(wfile, "{}", message);
}
}  // namespace tlog