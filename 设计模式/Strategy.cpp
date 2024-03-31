#include <iostream>
#include <vector>
#include <cmath>

class DiscountStrategy
{
public:
    virtual int applyDiscount(int originalPrice) = 0;
    virtual ~DiscountStrategy() = default;
};

class DiscountStrategy1 : public DiscountStrategy
{
public:
    int applyDiscount(int originalPrice) override
    {
        return static_cast<int>(std::round(originalPrice * 0.9));
    }
};

class DiscountStrategy2 : public DiscountStrategy
{
public:
    int applyDiscount(int originalPrice) override
    {
        for (int i = sizeof(threshold) / sizeof(threshold[0]) - 1; i >= 0; i--)
        {
            if (originalPrice >= threshold[i])
            {
                return originalPrice - discounts[i];
            }
        }
        return originalPrice;
    }

private:
    int threshold[4] = {100, 150, 200, 300};
    int discounts[4] = {5, 15, 25, 40};
};

class DiscountContext
{
private:
    DiscountStrategy *discountStrategy;

public:
    void setDiscountStrategy(DiscountStrategy *discountStrategy)
    {
        this->discountStrategy = discountStrategy;
    }

    int applyDiscount(int originalPrice)
    {
        return discountStrategy->applyDiscount(originalPrice);
    }
};

int main()
{
    int N;
    std::cin >> N;
    std::cin.ignore();

    for (int i = 0; i < N; i++)
    {
        int M, strategyType;

        std::cin >> M >> strategyType;

        DiscountStrategy *discountStrategy;

        switch (strategyType)
        {
        case 1:
            discountStrategy = new DiscountStrategy1();
            break;

        case 2:
            discountStrategy = new DiscountStrategy2();
            break;

        default:
            std::cout << "Unknown strategy type" << std::endl;
            return 1;
        }

        DiscountContext context;
        context.setDiscountStrategy(discountStrategy);

        int discountedPrice = context.applyDiscount(M);
        std::cout << discountedPrice << std::endl;

        delete discountStrategy;
    }
    return 0;
}