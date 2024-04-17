#include <memory>
#include <iostream>

template <class Ptr>
struct BlockList
{
    // 预定义内存块
    struct block;

    // 从指针类别 Ptr 定义指向内存块的指针
    // 若 Ptr 是任何 T* 类型，则 block_ptr_t 为 block*
    // 若 Ptr 是 smart_ptr<T> ，则 block_ptr_t 为 smart_ptr<block>
    using block_ptr_t = typename std::pointer_traits<Ptr>::template rebind<block>;

    struct block
    {
        std::size_t size;
        block_ptr_t next_block;
    };

    block_ptr_t free_blocks;
};

int main()
{
    BlockList<int *> bl1;
    // bl1.free_blocks 的类型是 block*

    BlockList<std::shared_ptr<char>> bl2;
    // bl2.free_blocks 的类型是 std::shared_ptr<block>
    std::cout << bl2.free_blocks.use_count() << '\n';
}