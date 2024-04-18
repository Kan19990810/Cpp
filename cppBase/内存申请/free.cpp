#include <cstdlib>
#include <iostream>
int main()
{
    int *p1 = (int *)std::malloc(10 * sizeof *p1);
    std::free(p1); // 每个分配的指针都必须释放

    int *p2 = (int *)std::calloc(10, sizeof *p2);
    int *p3 = (int *)std::realloc(p2, 1000 * sizeof *p3);

    // p3 非空表示 p2 为 std::realloc 所释放
    std::cout << "free p3\n";
    std::free(p3);

    std::free(nullptr);
}