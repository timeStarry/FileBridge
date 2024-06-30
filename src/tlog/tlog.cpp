#include <fmt/color.h>
#include <fmt/core.h>
#include <fmt/ostream.h>
#include <tlog.h>

#include <filesystem>
#include <fstream>
#include <ios>

namespace tlog {
auto tprint(std::initializer_list<std::string_view> src, tlog_status status,
            const std::pair<bool, std::string_view>& wf) -> void {
    if (src.size() == 0) {
        return;
    }
    std::string prefix;
    std::string val;

    for (const auto& i : src) {
        val += i;
    }
    switch (status) {
        case INFO:
            prefix = "[INFO]";
            break;
        case DEBUG:
            // rgb(255, 255, 0): yellow
            prefix = fmt::format(fg(fmt::rgb(255, 255, 0)), "[DEBUG]");
            break;
        case WARNNING:
            // rgb(0, 255, 255): blue
            prefix = fmt::format(fg(fmt::rgb(0, 255, 255)), "[WARNNING]");
            break;
        case ERROR:
            // rgb(255, 0, 0): red
            prefix = fmt::format(fg(fmt::rgb(255, 0, 0)), "[ERROR]");
            break;
        case SUCCESS:
            // rgb(0, 255, 0): green
            prefix = fmt::format(fg(fmt::rgb(0, 255, 0)), "[SUCCESS]");
            break;
    }
    fmt::print("{} {}\n", prefix, val);

    if (!wf.first) {
        return;
    }

    std::string path;
    if (wf.second.empty()) {
        path = "/tmp/filebridge.log";
    } else {
        path = wf.second;
    }
    if (!std::filesystem::exists(path)) {
        std::ofstream wfile{path, std::ios::binary};
        fmt::print(wfile, "{} {}\n", prefix, val);
    } else {
        std::ofstream wfile{path, std::ios::binary | std::ios::app};
        fmt::print(wfile, "{} {}\n", prefix, val);
    }
}
}  // namespace tlog