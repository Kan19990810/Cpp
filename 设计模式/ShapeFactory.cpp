#include <iostream>
#include <vector>

using namespace std;

class Block
{
public:
    virtual void produce() = 0;
};

class CircleBlock : public Block
{
public:
    void produce() override
    {
        cout << "Circle Block" << endl;
    }
};

class SquareBlock : public Block
{
public:
    void produce() override
    {
        cout << "Square Block" << endl;
    }
};

class BlockFactory
{
public:
    virtual Block *creatBlock() = 0;
};

class CircleBlockFactory : public BlockFactory
{
public:
    Block *creatBlock() override
    {
        return new CircleBlock();
    }
};

class SquareBlockFactory : public BlockFactory
{
public:
    Block *creatBlock() override
    {
        return new SquareBlock();
    }
};

class BlockFatorySystem
{
private:
    std::vector<Block *> blocks;

public:
    void produceBlocks(BlockFactory *factory, int quantity)
    {
        for (int i = 0; i < quantity; i++)
        {
            Block *block = factory->creatBlock();
            blocks.push_back(block);
            block->produce();
        }
    }

    const vector<Block *> &getBlocks() const
    {
        return blocks;
    }

    ~BlockFatorySystem()
    {
        for (Block *block : blocks)
        {
            delete block;
        }
    }
};

int main()
{
    BlockFatorySystem factorySystem;

    int productionCount;

    cin >> productionCount;

    for (int i = 0; i < productionCount; i++)
    {
        string blockType;
        int quantity;
        cin >> blockType >> quantity;
        if (blockType == "Circle")
        {
            factorySystem.produceBlocks(new CircleBlockFactory(), quantity);
        }
        else if (blockType == "Square")
        {
            factorySystem.produceBlocks(new SquareBlockFactory(), quantity);
        }
    }
    return 0;
}