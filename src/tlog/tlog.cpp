#include <tlog.h>
#include <fmt/core.h>

namespace tlog{
    auto tprint(const std::string& src, tlog_status status) -> void{
        switch (status) {
            case INFO:
                fmt::print("[INFO] {}", src);
                break;
            case DEBUG:
                fmt::print("[DEBUG] {}", src);
                break;
            case WARNING:
                fmt::print("[WARNING] {}", src);
                break;
            case ERROR:
                fmt::print("[ERROR] {}", src);
                break;
        }
    }
}  // namespace tlog