#include <iostream>
#include <string>

void work(const std::string &s)
{
    std::cout << "const &:" << s << std::endl;
}

void work(std::string &&s)
{
    std::cout << "&&:" << s << std::endl;
}

template <typename... Args>
void forward(Args &&...args)
{
    work(std::forward<Args>(args)...);
}

int main()
{
    const std::string str1 = "I am const lvalue";
    forward(str1);
    forward("I am a rvalue");
    return 0;
}
