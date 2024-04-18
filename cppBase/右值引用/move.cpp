#include <iostream>    // std::cout
#include <type_traits> // std::is_same
#include <vector>
#include <string>
template <class T1, class T2>
void print_is_same()
{
    std::cout << std::is_same<T1, T2>() << '\n';
}

struct Bad
{
    Bad() {}
    Bad(Bad &&) // 可能抛出
    {
        std::cout << "Throwing move constructor called\n";
    }
    Bad(const Bad &) // 亦可能抛出
    {
        std::cout << "Throwing copy constructor called\n";
    }
};

struct Good
{
    Good() {}
    Good(Good &&) noexcept // 将不抛出
    {
        std::cout << "Non-throwing move constructor called\n";
    }
    Good(const Good &) noexcept // 将不抛出
    {
        std::cout << "Non-throwing copy constructor called\n";
    }
};

int main()
{
    // {
    //     std::cout << std::boolalpha;

    //     print_is_same<int, int>();
    //     print_is_same<int, int &>();
    //     print_is_same<int, int &&>();

    //     print_is_same<int, std::remove_reference<int>::type>();
    //     print_is_same<int, std::remove_reference<int &>::type>();
    //     print_is_same<int, std::remove_reference<int &&>::type>();
    // }

    // {
    //     std::string str = "Hello";
    //     std::vector<std::string> v;

    //     // 使用 push_back(const T&) 重载，
    //     // 表示我们将带来复制 str 的成本
    //     v.push_back(str);
    //     std::cout << "After copy, str is \"" << str << "\"\n";

    //     // 使用右值引用 push_back(T&&) 重载，
    //     // 表示不复制字符串；而是
    //     // str 的内容被移动进 vector
    //     // 这个开销比较低，但也意味着 str 现在可能为空。
    //     v.push_back(std::move(str));
    //     std::cout << "After move, str is \"" << str << "\"\n";

    //     std::cout << "The contents of the vector are \"" << v[0]
    //               << "\", \"" << v[1] << "\"\n";
    // }

    // {
    //     Good g;
    //     Bad b;
    //     Good g2 = std::move_if_noexcept(g);
    //     Bad b2 = std::move_if_noexcept(b);
    // }

    struct t
    {
        int x1;
        t()
        {
            std::cout << &x1 << std::endl;
            std::cout << "construct\n";
        }

        t(const int &x) : x1(x)
        {
            std::cout << &x1 << std::endl;
            std::cout << "lvalue construct\n";
        }
        t(int &&x) : x1(x)
        {
            std::cout << &x1 << std::endl;
            std::cout << "rvalue construct\n";
        }
        t(const t &x) noexcept : x1(x.x1)
        {
            std::cout << &x1 << std::endl;
            std::cout << "lvalue construct\n";
        }
        t(t &&x) noexcept : x1(x.x1)
        {
            std::cout << &x1 << std::endl;
            std::cout << "rvalue construct\n";
        }

        ~t()
        {
            std::cout << "deconstruct\n";
        }
    };

    {
        t t0;

        t t1(t0);

        t t2(std::move(t0));
    }
}