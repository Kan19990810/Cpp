#include <iostream>
#include <memory>

std::weak_ptr<int> gw;

void f()
{
    std::cout << "usecount: " << gw.use_count() << std::endl;
    std::cout << "expired: " << std::boolalpha << gw.expired() << std::endl;
    std::cout << "lock: " << gw.lock() << std::endl;
}

int main()
{
    {
        auto sp = std::make_shared<int>(42);
        gw = sp;
        f();
    }
    f();
}