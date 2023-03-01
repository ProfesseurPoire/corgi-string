#include <corgi/string/string.h>

namespace corgi::string
{
void chop(std::string& str, size_t n)
{
    if(n >= str.size()) [[unlikely]]
    {
        str = "";
        return;
    }

    str.resize(str.size() - n);
}

std::string chopped(const std::string& str, size_t n)
{
    if(n >= str.size())
        return "";

    return str.substr(0, str.size() - n);
}

bool ends_with(const std::string& str, const std::string& end)
{
    auto result = str.rfind(end);

    if(result == std::string::npos)
        return false;

    return (result == str.size() - end.size());
}

bool starts_with(const std::string& str, const std::string& start)
{
    auto result = str.find(start);

    if(result == std::string::npos)
        return false;

    return result == 0;
}

}    // namespace corgi::string