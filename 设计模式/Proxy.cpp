#include <iostream>

class HomePurchase
{
public:
    virtual void requesetPurchase(int area) = 0;
};

class HomeBuyer : public HomePurchase
{
public:
    void requestPurchase(int area) override
    {
        std::cout << "Yes" << std::endl;
    }
};

class HomeAgentProxy : public HomePurchase
{
private:
    HomeBuyer homeBuyer;

public:
    void requestPurchase(int area) override
    {
        if (area > 100)
        {
            homeBuyer.requestPurchase(area);
        }
        else
        {
            std::cout << "No" << std::endl;
        }
    }
};

int main()
{
    HomePurchase *buyerProxy = new HomeAgentProxy();
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        int area;
        std::cin >> area;
        buyerProxy->requesetPurchase(area);
    }

    delete buyerProxy;
    return 0;
}