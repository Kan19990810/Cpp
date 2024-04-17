#include <iostream>

using namespace std;

// 编译时多态， 继承基类的特定模板
template <typename T>
struct Base
{
    void foo()
    {
        (static_cast<T *>(this))->foo();
    }
};

struct Derived : public Base<Derived>
{
    void foo()
    {
        cout << "derived foo" << endl;
    }
};

struct AnotherDerived : public Base<AnotherDerived>
{
    void foo()
    {
        cout << "anotherderived foo" << endl;
    }
};

// 推导 derived
//  Derived* &d1
// T Derived
template <typename T>
void processFoo(Base<T> *b)
{
    b->foo();
};

int main()
{
    Derived d1;
    AnotherDerived d2;
    processFoo(&d1);
    processFoo(&d2);
    return 0;
}