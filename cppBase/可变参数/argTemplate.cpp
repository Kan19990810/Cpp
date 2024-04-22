// forward.cpp
#include <iostream>
#include <string>

void work(const int value)
{
    std::cout << "const int:" << value << std::endl;
}

void work(const double value)
{
    std::cout << "const double:" << value << std::endl;
}

void work(const std::string value)
{
    std::cout << "const string:" << value << std::endl;
}

void processValue()
{
}

template <typename Arg, typename... Args>
void processValue(Arg arg1, Args... args)
{
    work(arg1);
    processValue(args...);
}

int main()
{
    processValue(1, 2, 3, 4.1, 5.2, "6", "7");
    return 0;
}
