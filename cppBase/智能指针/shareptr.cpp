#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>

struct Base
{
    Base() { std::cout << "  Base::Base()\n"; }
    void print() { std::cout << "  Base Print\n"; }
    // 注意：此处非虚析构函数 OK
    ~Base() { std::cout << "  Base::~Base()\n"; }
};

struct Derived : public Base
{
    Derived() { std::cout << "  Derived::Derived()\n"; }
    void print() { std::cout << " Derived Print\n"; }
    ~Derived() { std::cout << "  Derived::~Derived()\n"; }
};

struct De
{
    void operator()(Base *b) const
    {
        std::cout << "Call Delete for Base\n";
        delete b;
    }
};

void thr(std::shared_ptr<Base> p)
{
    std::cout << "local pointer in a thread:\n"
              << "  l.get() = " << p.get()
              << ", l.use_count() = " << p.use_count() << '\n';
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::shared_ptr<Base> lp = p; // 线程安全，虽然自增共享的 use_count
    {
        static std::mutex io_mutex;
        std::lock_guard<std::mutex> lk(io_mutex);
        std::cout << "local pointer in a thread:\n"
                  << "  lp.get() = " << lp.get()
                  << ", lp.use_count() = " << lp.use_count() << '\n';
    }
}

int main()
{
    // {
    //     // 只有共享指针能够在父类的析构函数不是虚函数时触发
    //     std::shared_ptr<Base> p = std::make_shared<Derived>();
    //     std::cout << "Created a shared Derived (as a pointer to Base)\n"
    //               << "  p.get() = " << p.get()
    //               << ", p.use_count() = " << p.use_count() << '\n';
    // }

    // {
    //     std::shared_ptr<Base> p = std::make_shared<Derived>();
    //     std::thread t1(thr, p), t2(thr, p), t3(thr, p);
    //     p.reset(); // 从 main 释放所有权
    //     std::cout << "Shared ownership between 3 threads and released\n"
    //               << "ownership from main:\n"
    //               << "  p.get() = " << p.get()
    //               << ", p.use_count() = " << p.use_count() << '\n';
    //     t1.join();
    //     t2.join();
    //     t3.join();
    //     std::cout << "All threads completed, the last one deleted Derived\n";
    // }
    {
        // 设置仅空指针不会调用析构函数
        Base *b = new Base();
        std::shared_ptr<Base> p(nullptr);
        std::cout << p.use_count() << std::endl;
        // delete b;
        // std::cout << "finish\n";
    }

    {
        // 设置空指针且定义了删除器会调用析构函数
        Base *b = new Base();
        std::shared_ptr<Base> p(nullptr, De());
        std::cout << p.use_count() << std::endl;
        // delete b;
        // std::cout << "finish\n";
    }
    return 0;
}