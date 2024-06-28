#include <initializer_list>
#include <string>

namespace tlog {
enum tlog_status { DEBUG, INFO, WARNNING, ERROR };
auto tprint(std::initializer_list<const std::string> src, tlog_status status) -> void;
}  // namespace tlog