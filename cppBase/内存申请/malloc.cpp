#include <iostream>
#include <cstdlib>
#include <string>
#include <cassert>
#include <new>

int main()
{
    // // 为 4 个 string 的数组分配足够空间
    // {
    //     if (auto p = (std::string *)std::malloc(4 * sizeof(std::string)))
    //     {
    //         int i = 0;
    //         try
    //         {
    //             for (; i != 4; ++i) // 填充数组
    //                 new (p + i) std::string(5, 'a' + i);

    //             for (int j = 0; j != 4; ++j) // 打印出来
    //                 std::cout << "p[" << j << "] == " << p[j] << '\n';
    //         }
    //         catch (...)
    //         {
    //         }

    //         for (; i != 0; --i) // 清理
    //             p[i - 1].~basic_string();

    //         std::free(p);
    //     }
    // }

    {

        class MallocDynamicBuffer
        {

        public:
            char *p;
            explicit MallocDynamicBuffer(std::size_t initial = 0) : p(nullptr)
            {
                resize(initial);
            }
            ~MallocDynamicBuffer() { std::free(p); }
            void resize(std::size_t newSize)
            {
                if (newSize == 0)
                { // 此检查并非严格需要，但零大小 realloc 于 C 中弃用
                    std::free(p);
                    p = nullptr;
                }
                else
                {
                    if (void *mem = std::realloc(p, newSize))
                        p = static_cast<char *>(mem);
                    else
                        throw std::bad_alloc();
                }
            }
            char &operator[](size_t n) { return p[n]; }
            char operator[](size_t n) const { return p[n]; }
        };

        MallocDynamicBuffer buf1(1024);
        buf1[5] = 'f';
        buf1.resize(1); // 收缩
        std::cout << buf1.p << ' ' << buf1[5] << std::endl;
        buf1.resize(0); // 增长
        std::cout << buf1[5] << std::endl;
    }

    return 0;
}