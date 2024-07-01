#include <initializer_list>
#include <string_view>
#include <utility>

namespace tlog {
enum tlog_status { SUCCESS, DEBUG, INFO, WARNNING, ERROR };

constexpr std::pair<bool, std::string_view> NO_LOG_FILE{false, ""};
constexpr std::pair<bool, std::string_view> DEFAULT_LOG_FILE{true, ""};

/*
 * @brief formatted output with log levels
 *
 * @note this function is still under development
 *
 * @param `std::initializer_list<const std::string> src` is the string to be
 * output, pass the string in with `{"file: ", val}`
 * @param `tlog_status status` is an enum type, the value is `DEBUG`, `INFO`,
 * `WARNNING`, `ERROR`. If it is `ERROR` or `WARNNING`, it will be printed to
 * `stderr`, otherwise it will be printed to `stdoout`.
 * @param `wf` determine whether the log message is saved to the file, if the
 * `wf.first` is true, It means to save it in the file. `wf.second` is the file
 * path. You can choose between the two default values ​​provided by
 * `NO_LOG_FILE` and `DEFAULT_LOG_FILE` to choose not to generate a log file or
 * use the default log file storage path.
 */
auto tprint(std::initializer_list<std::string_view> src, tlog_status status,
            const std::pair<bool, std::string_view>& wf) -> void;
}  // namespace tlog