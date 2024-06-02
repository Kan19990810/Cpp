#include <iostream>

int main()
{
    while (true)
    {
        int *ptr = new int(10); // 动态分配内存
        // ... 这里可能进行一些操作
        // 忘记释放内存
        // delete ptr; // 正确释放内存的语句
    }
    return 0;
}
