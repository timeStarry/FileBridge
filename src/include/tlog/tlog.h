#include <string>

namespace tlog {
enum tlog_status { DEBUG, INFO, WARNING, ERROR };
auto tprint(const std::string& src, tlog_status status) -> void;
}  // namespace tlog