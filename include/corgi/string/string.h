#pragma once

#include <string>

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
 * @brief   Removes a string that contains the n characters from the end of the given string 
 */
[[nodiscard]] std::string chopped(const std::string& str, size_t n);

/**
 * @brief   Removes a string that contains the n characters from the end of the given string 
 */
[[nodiscard]] auto chopped_likely(const std::string& str, size_t n) -> std::string;

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
void ljust(std::string& str, size_t size, char c = ' ');

/**
 * @brief right justifies the string parameter @p str
 */
void rjust(std::string& str, size_t size, char c = ' ');

/**
 * @brief   strips the left characters from the string
 * 
 *          mostly used without argument to remove the white spaces
*/
void lstrip(std::string& str, const std::string& chars = " \t");

/**
 * @brief   Strips the right characters from the string
 * 
 *          Mostly used without argument to remove white spaces from a string
 */
void rstrip(std::string& str, const std::string& chars = " \t");

}    // namespace string
}    // namespace corgi