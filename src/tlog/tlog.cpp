#include <fmt/color.h>
#include <fmt/core.h>
#include <tlog.h>

#include <string>

namespace tlog {
auto tprint(std::initializer_list<const std::string> src, tlog_status status)
    -> void {
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
}
}  // namespace tlog