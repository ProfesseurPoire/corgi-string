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
[[nodiscard]] std::string chopped_likely(const std::string& str, size_t n);

/**
 * @brief   Returns true if the given str string ends with the given end string
*/
[[nodiscard]] bool ends_with(const std::string& str, const std::string& end);

}    // namespace string
}    // namespace corgi