#include <initializer_list>
#include <string>

namespace tlog {
enum tlog_status { DEBUG, INFO, WARNNING, ERROR };
/*
* @brief formatted output with log levels
* 
* @note this function is still under development
* 
* @param `std::initializer_list<const std::string> src` is the string to be output, pass the string in with `{"file: ", val}`
* @param `tlog_status status` is an enum type, the value is `DEBUG`, `INFO`, `WARNNING`, `ERROR`
*/
auto tprint(std::initializer_list<const std::string> src, tlog_status status) -> void;
}  // namespace tlog