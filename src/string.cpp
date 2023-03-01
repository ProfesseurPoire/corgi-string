#include <corgi/string/string.h>

#include <algorithm>
#include <cctype>
#include <string>

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

void to_lower(std::string& str)
{
    std::transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char c)
                   { return static_cast<char>(std::tolower(static_cast<int>(c))); });
}

void to_upper(std::string& str)
{
    std::transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char c)
                   { return static_cast<char>(std::toupper(static_cast<int>(c))); });
}

bool is_upper(const std::string& str)
{
    for(const auto& c : str)
    {
        if(std::islower(static_cast<int>(c)))
            return false;
    }
    return true;
}

bool is_lower(const std::string& str)
{
    for(const auto& c : str)
    {
        if(std::isupper(static_cast<int>(c)))
            return false;
    }
    return true;
}

void capitalize(std::string& str)
{
    to_lower(str);

    if(str.size() > 0)
        str[0] = static_cast<char>(std::toupper(static_cast<int>(str[0])));
}

bool is_alpha_num(const std::string& str)
{
    if(str.empty())
        return false;

    for(const auto& c : str)
    {
        if(!std::isalnum(static_cast<int>(c)))
            return false;
    }
    return true;
}

bool is_alpha(const std::string& str)
{
    if(str.empty())
        return false;

    for(const auto& c : str)
    {
        if(!std::isalpha(static_cast<int>(c)))
            return false;
    }
    return true;
}

bool is_decimal(const std::string& str)
{
    if(str.empty())
        return false;

    for(const auto& c : str)
    {
        if(!std::isdigit(static_cast<int>(c)))
            return false;
    }
    return true;
}

bool is_number(const std::string& str)
{
    try
    {
        std::stoi(str);
        std::stof(str);
    }
    catch(const std::exception&)
    {
        return false;
    }
    return true;
}

void pad_right(std::string& str, size_t size, char c)
{
    auto previous_size = str.size();
    str.resize(size);

    for(size_t i = 0; i < size; i++)
    {
        if(i >= previous_size)
            str[i] = c;
    }
}

void pad_left(std::string& str, size_t size, char c)
{
    if(size < str.size())
        return;

    auto previous_size = str.size();
    str.reserve(size);
    str.insert(str.begin(), size - previous_size, c);
}

void trim_start(std::string& str, const std::string& chars)
{
    size_t i = 0;

    while(i < str.size())
    {
        auto found = chars.find(str[i]);

        if(found != std::string::npos)
        {
            str.erase(str.begin() + i--);
        }
        else
            return;
        i++;
    }
}

void trim_end(std::string& str, const std::string& chars)
{
    int i = static_cast<int>(str.size() - 1);

    while(i >= 0)
    {
        auto found = chars.find(str[i]);

        if(found != std::string::npos)
        {
            str.erase(str.begin() + i);
        }
        else
            return;
        i--;
    }
}

void trim(std::string& str, const std::string& chars)
{
    trim_start(str, chars);
    trim_end(str, chars);
}

std::vector<std::string> split(const std::string& str, const std::string& separator)
{
    std::vector<std::string> sub_strings;
    size_t                   start = 0;

    auto result = str.find(separator, start);

    while(result != std::string::npos)
    {
        sub_strings.push_back(str.substr(start, result));
        start  = result + separator.size();
        result = str.find(separator, start);
    }

    sub_strings.push_back(str.substr(start, result));

    return sub_strings;
}

void truncate(std::string& str, size_t n)
{
    str.erase(n, std::string::npos);
}

}    // namespace corgi::string