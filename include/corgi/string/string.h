#pragma once

#include <string>
#include <vector>

namespace corgi
{
namespace string
{
/**
 * @brief Removes n characters from the end of the string
 * 
 *        if n is greater than the size of the string, return an empty string
 */
void chop(std::string& str, size_t n);

/**
 * @brief   Returns true if the given str string ends with the given end string
*/
[[nodiscard]] bool ends_with(const std::string& str, const std::string& end);

/**
 * @brief   Returns true if the string parameter @p str starts with string parameter @p start 
*/
[[nodiscard]] bool starts_with(const std::string& str, const std::string& start);

/**
 * @brief   Lowers the string parameter @p str
 * 
 *          Lowering means the string will only contains lower case characters
*/
void to_lower(std::string& str);

/**
 * @brief   Uppers the string parameter @p str
*/
void to_upper(std::string& str);

/**
 * @brief   Checks whether or not string parameter @p str is in upper case
 * 
 *          Returns true if the string is upper case, return false otherwise
*/
[[nodiscard]] bool is_upper(const std::string& str);

/**
 * @brief   Checks whether or not string parameter @p str is in lower case
 * 
 *          Returns true if the string is in lower case, return false otherwise. 
 */
[[nodiscard]] bool is_lower(const std::string& str);

/**
 * @brief   Capitalizes the first letter and lower the rest of the string parameter @p str
 */
void capitalize(std::string& str);

/**
 * @brief   Checks whether string parameter @p str contains only alpha numerical characters
 */
[[nodiscard]] bool is_alpha_num(const std::string& str);

/**
 * @brief   Checks whether string parameter @p str contains only alphabetics characters 
 */
[[nodiscard]] bool is_alpha(const std::string& str);

/**
 * @brief   Checks whether string parameter @p str contains a decimal number 
 */
[[nodiscard]] bool is_decimal(const std::string& str);

/**
 * @brief   Checks whether string parameter @p str is a number or not
 */
[[nodiscard]] bool is_number(const std::string& str);

/**
 * @brief left justifies the string parameter @p str
 */
void pad_right(std::string& str, size_t size, char c = ' ');

/**
 * @brief right justifies the string parameter @p str
 */
void pad_left(std::string& str, size_t size, char c = ' ');

/**
 * @brief   strips the left characters from the string
 * 
 *          mostly used without argument to remove the white spaces
*/
void trim_start(std::string& str, const std::string& chars = " \t\n\f\r");

/**
 * @brief   Strips the right characters from the string
 * 
 *          Mostly used without argument to remove white spaces from a string
 */
void trim_end(std::string& str, const std::string& chars = " \t\n\f\r");

/**
 * @brief   Strips the left and right characters from the string 
 */
void trim(std::string& str, const std::string& chars = " \t\n\f\r");

/**
 * @brief   Splits the string parameter @p str using the given separator @p separator
 */
[[nodiscard]] std::vector<std::string> split(const std::string& str,
                                             const std::string& separator);

/**
 * @brief Truncate the string 
 */
void truncate(std::string& str, size_t n);

}    // namespace string
}    // namespace corgi