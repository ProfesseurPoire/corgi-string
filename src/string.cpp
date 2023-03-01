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

void ljust(std::string& str, size_t size, char c)
{
    auto previous_size = str.size();
    str.resize(size);

    for(size_t i = 0; i < size; i++)
    {
        if(i >= previous_size)
            str[i] = c;
    }
}

void rjust(std::string& str, size_t size, char c)
{
    auto previous_size = str.size();
    str.reserve(size);
    str.insert(str.begin(), size - previous_size, c);
}

void lstrip(std::string& str, const std::string& chars)
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

void rstrip(std::string& str, const std::string& chars)
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

}    // namespace corgi::string