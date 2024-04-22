#include <stdio.h>
#include <stdarg.h>

// 可变参数 25， 25 ，50 50
int add_nums(int count, ...)
{
    int result = 0;
    va_list args;
    // va_start 初始化 va_list, 并指定参数个数
    va_start(args, count);
    for (int i = 0; i < count; ++i)
    {
        // va_arg 返回va_list的参数，并指定下一个参数的类型
        result += va_arg(args, int);
    }
    // va_end 清理va_list对象
    va_end(args);
    return result;
}

int main(void)
{
    printf("%d\n", add_nums(4, 25, 25, 50, 50));
}