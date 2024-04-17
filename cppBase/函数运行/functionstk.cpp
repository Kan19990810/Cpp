#include <iostream>
using namespace std;

// 入栈方式 返回值 z y z
void *fun(int x, int y, int z)
{
    cout << "x: " << x << &x << endl;
    cout << "y: " << y << &y << endl;
    cout << "z: " << z << &z << endl;
}

int main(int argc, char *argv[])
{
    cout << "func: " << fun(1, 2, 3) << endl;
    // system("pause");
    return 0;
}
