#include <new>
#include <memory>
#include <iostream>
#include <string>
using namespace std;
class memTest
{
public:
    static int num;
    memTest()
    {
        cout << "Constructor from object " << num++ << endl;
        // cout << "Constructor address at " << this << endl;
    }
    ~memTest()
    {
        cout << "Destructor from object " << --num << endl;
        // cout << "Deconstructor address at " << this << endl;
    }
};
int memTest::num = 0;
int main()
{
    {
        memTest *Test1 = new memTest[3];

        delete Test1; //<-----
    }

    // {
    //     memTest *Test1 = new memTest[3];

    //     delete[] Test1; //<-----
    // }

    // // new [] delte[]
    // {
    //     int *q = new int[10]{3, 4};
    //     // int *p = new int(1);
    //     auto tmp = q;
    //     // auto tmp2 = p;
    //     // delete p;
    //     cout << *tmp << endl;

    //     delete[] q;

    //     cout << *tmp << endl;
    // }

    // {
    //     // 申请预缓冲区 在预缓冲区中申请内存
    //     char *buf = new char[sizeof(string)];  // pre-allocated buffer
    //     string *p = new (buf) string("hello"); // placement new
    //     string *q = new string("word");        // ordinary heap allocation

    //     cout << "buf: " << (string *)buf << " *buf:" << *(string *)buf << endl;
    //     cout << "*p: " << p << " *p:" << *p << endl;
    //     cout << "*q: " << q << " *q:" << *q << endl;

    //     delete[] buf;
    // }

    return 0;
}