#include <tlog.h>
#include <fmt/core.h>
#include <fmt/color.h>
#include <string>

namespace tlog{
    auto tprint(std::initializer_list<const std::string> src, tlog_status status) -> void{
        if(src.size() == 0){
            return;
        }
        std::string val;

        std::string tmp;
        for(const auto& i : src){
            tmp += i;
        }
        switch (status) {
            case INFO:
                // rgb(0, 255, 0): green
                val = fmt::format(fg(fmt::rgb(0, 255, 0)), "[INFO]");
                break;
            case DEBUG:
                // rgb(255, 255, 0): yellow
                val = fmt::format(fg(fmt::rgb(255, 255, 0)), "[DEBUG]");
                break;
            case WARNNING:
                // rgb(0, 255, 255): blue
                val = fmt::format(fg(fmt::rgb(0, 255, 255)), "[WARNNING]");
                break;
            case ERROR:
                // rgb(255, 0, 0): red
                val = fmt::format(fg(fmt::rgb(255, 0, 0)), "[ERROR]");
                break;
        }
        fmt::print("{} {}\n", val, tmp);
    }
}  // namespace tlog