#include <iostream>
#include <map>

using namespace std;

class ShoppingCartManager
{
public:
    static ShoppingCartManager &getInstance()
    {
        static ShoppingCartManager instance;
        return instance;
    }

    void addToCart(const string &itemName, int quantity)
    {
        cart[itemName] += quantity;
    }

    void viewCart() const
    {
        for (const auto &item : cart)
        {
            cout << item.first << ' ' << item.second << endl;
        }
    }

private:
    // 私有的构造函数
    ShoppingCartManager()
    {
    }

    // 私有的数据
    map<string, int> cart;
};

int main()
{
    string itemName;
    int quantity;

    while (cin >> itemName >> quantity)
    {
        ShoppingCartManager &cart = ShoppingCartManager::getInstance();
        cart.addToCart(itemName, quantity);
    }
    const ShoppingCartManager &cart = ShoppingCartManager::getInstance();
    cart.viewCart();
    return 0;
}

/**
 *
 *
 * class single{
 * public:
 *      static single &getinstance(){
 *          static single instance;
 *          return instance;
 * }
 *
 * private:
 *      single(){}
 *
 * }
 */