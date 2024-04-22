

// debug_print.cpp
#include <iostream>
#include <string>

// 基础版本
template <typename T>
std::ostream &print(std::ostream &os, const T &param)
{
    os << "last parameter: ";
    os << param << std::endl;
    ;
    return os;
}

// 可变参数版本
template <typename T, typename... Args>
std::ostream &print(std::ostream &os, const T &param, const Args &...args)
{
    os << sizeof...(args) << " remaining parameters: ";
    os << param << std::endl;
    return print(os, args...);
}

// 单参数加debug印记
template <typename T>
std::string debug_prefix(const T &t)
{
    return "debug:" + std::to_string(t);
}

// 可变参数包统一添加debug印记
template <typename... Args>
std::ostream &debug_print(std::ostream &os, const Args &...rest)
{
    return print(os, debug_prefix(rest)...);
}

int main()
{
    debug_print(std::cout, 2.3, 4.5, 1, 2 + 3);
    return 0;
}