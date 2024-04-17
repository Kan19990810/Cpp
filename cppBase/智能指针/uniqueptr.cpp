#include <iostream>
#include <vector>
#include <memory>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <functional>

struct C
{
    C() { std::cout << "C::C\n"; }
    ~C() { std::cout << "C::~C\n"; }
};

struct B
{
    // C c;
    B() { std::cout << "B::B\n"; }
    virtual void bar() { std::cout << "B::bar\n"; }
    virtual ~B() { std::cout << "B::~B\n"; }
};
struct D : B
{
    int x;
    D()
    {
        std::cout << "D::D\n";
    }
    ~D()
    {
        std::cout << "D::~D\n";
    }
    void bar() override { std::cout << "D::bar\n"; }
};
// 消费 unique_ptr 的函数能以值或以右值引用接收它
std::unique_ptr<D> pass_through(std::unique_ptr<D> p)
{
    p->bar();
    return p;
}

void close_file(std::FILE *fp) { std::fclose(fp); }

struct Foo
{
    Foo() { std::cout << "Foo...\n"; }
    ~Foo() { std::cout << "~Foo...\n"; }
};

struct De
{
    void bar() { std::cout << "Call deleter D::bar()...\n"; }
    void operator()(Foo *p) const
    {
        std::cout << "Call delete for Foo object...\n";
        delete p;
    }
};

int main()
{
    // {
    //     // 智能指针在父类指针拥有子类指针的情况
    //     // 需要讲父类析构设置为虚函数
    //     std::unique_ptr<B> uniq = std::make_unique<D>();
    // }

    // {
    //     // 自定义删除函数
    //     auto deleter = [](int *ptr)
    //     {
    //         std::cout << "[deleter called]\n";
    //         delete ptr;
    //     };

    //     std::unique_ptr<int, decltype(deleter)> uniq(new int, deleter);
    //     std::cout << (uniq ? "not empty\n" : "empty\n");
    //     uniq.reset();
    //     std::cout << (uniq ? "not empty\n" : "empty\n");
    // }

    // {
    //     // 析构函数中调用get_deleter()
    //     std::unique_ptr<Foo, De> up(new Foo(), De());
    //     De &del = up.get_deleter();
    //     del.bar();
    // }

    {
        // 定义空指针不会调用析构函数
        std::unique_ptr<Foo, De> up(nullptr, De());
        std::cout << "finish\n";
    }

    // {
    //     // 局部变量构造 会进行报错
    //     int h{100};
    //     int x = 1;
    //     std::unique_ptr<int> temp1{&x};

    //     std::cout << "temp1.get() :" << temp1.get() << std::endl;
    //     std::cout << "&h : " << &h << std::endl;
    //     std::cout << "*temp : " << *temp1 << std::endl;
    // }

    // {
    //     std::cout << "Example constructor(2)...\n";
    //     std::unique_ptr<Foo> up2(new Foo); // up2 现在占有 Foo
    //                                        // Foo 被删除
    // }

    // {
    //     std::cout << "unique ownership semantics demo\n";
    //     auto p = std::make_unique<D>(); // p 是占有 D 的 unique_ptr
    //     auto q = pass_through(std::move(p));
    //     assert(!p); // 现在 p 不占有任何内容并保有空指针
    //     std::cout << "p==nullptr " << (p == nullptr) << std::endl;
    //     q->bar(); // 而 q 占有 D 对象
    // }             // ~D 调用于此

    // {
    //     // vector管理智能指针
    //     std::cout << "Runtime polymorphism demo\n";
    //     std::unique_ptr<B> p = std::make_unique<D>(); // p 是占有 D 的 unique_ptr
    //                                                   // 作为指向基类的指针
    //     p->bar();                                     // 虚派发
    //     std::vector<std::unique_ptr<B>> v;            // unique_ptr 能存储于容器
    //     v.push_back(std::make_unique<D>());
    //     v.push_back(std::move(p));
    //     v.emplace_back(new D);
    //     for (auto &p : v)
    //         p->bar(); // 虚派发
    // }                 // ~D called 3 times

    // {
    //     // 删除器定义为关闭文件
    //     std::cout << "Custom deleter demo\n";
    //     std::ofstream("demo.txt") << 'x'; // 准备要读的文件
    //     std::unique_ptr<std::FILE, void (*)(std::FILE *)> fp(std::fopen("demo.txt", "r"), close_file);
    //     if (fp) // fopen 可以打开失败；该情况下 fp 保有空指针
    //         std::cout << (char)std::fgetc(fp.get()) << '\n';
    // } // fclose() 调用于此，但仅若 FILE* 不是空指针
    // // （即 fopen 成功）

    // { // 自定义删除函数
    //     std::cout << "Custom lambda-expression deleter demo\n";
    //     std::unique_ptr<D, std::function<void(D *)>> p(new D, [](D *ptr)
    //                                                    {
    //         std::cout << "destroying from a custom deleter...\n";
    //         delete ptr;
    //         std::cout << "destroying finish...\n"; }); // p 占有 D
    //     p->bar();
    // } // 调用上述 lambda 并销毁 D

    // {
    //     std::cout << "Array form of unique_ptr demo\n";
    //     std::unique_ptr<D[]> p{new D[3]};
    // } // 调用 ~D 3 次

    return 0;
}