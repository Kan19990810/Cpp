#include <string>
#include <memory>
#include <iostream>
using namespace std;

class Object
{
public:
    Object(const string &str)
    {
        cout << "Constructor " << str << endl;
    }

    Object()
    {
        cout << "Default constructor" << endl;
    }

    ~Object()
    {
        cout << "Destructor" << endl;
    }

    Object(const Object &rhs)
    {
        cout << "Copy constructor..." << endl;
    }
};

void make_shared_example()
{
    cout << "make_shared..." << endl;
    auto ptr_res1 = make_shared<Object>("make_shared");
    cout << "make_shared: done." << endl;
    cout << "******************" << endl;
    cout << "using new..." << endl;
    shared_ptr<Object> ptr_res2(new Object("new"));
    cout << "using new: done." << endl;
}

int main()
{
    make_shared_example();
    return 0;
}