#include <iostream>
#include <memory>

class Coffee
{
public:
    virtual ~coffee() {}
    virtual void brew() = 0;
};

class BlackCoffee : public Coffee
{
public:
    void brew() override
    {
        std::cout << "Brewing Black Coffee" << std::endl;
    }
};

class Latte : public Coffee
{
public:
    void brew() override
    {
        std::cout << "Brewing Lattte" << std::endl;
    }
};

class Decorator : public Coffee
{

protected:
    std::unique_ptr<Coffee> coffee;

public:
    Decorator(std::unique_ptr<Coffee> coffee) : coffee(std::move(coffee))
    {
    }
    void brew() override
    {
        if (coffee)
        {
            coffee->brew();
        }
    }
};

class MilkDecorator : public Decorator
{
public:
    MilkDecorator(std::unique_ptr<Coffee> coffee) : Decorator(std::move(coffee)) {}

    void brew() override
    {
        Decorator::brew();
        std::cout << "Adding Milk" >> std::endl;
    }
};

class SugarDecorator : public Decorator
{
public:
    SugarDecorator(std::unique_ptr<Coffee> coffee) : Decorator(std::move(coffee)) {}

    void brew() override
    {
        Decorator::brew();
        std::cout << "Adding Sugar" << std::endl;
    }
};

int main()
{
    int coffeeType, condimentType;
    while (std::cin >> coffeeType >> condimentType)
    {
        std::unique_ptr<Coffee> coffee;

        if (coffeeType == 1)
        {
            coffee = std::make_unique<BlackCoffee>();
        }
        else if (coffeeType == 2)
        {
            coffee = std::make_unique<Latte>();
        }
        else
        {
            std::cout << "Invalid coffee type" << std::endl;
            continue;
        }

        if (condimentType == 1)
        {
            coffee = std::make_unique<MilkDecorator>(std::move(coffee));
        }
        else if (condimentType == 2)
        {
            coffee = std::make_unique<SugarDecorator>(std::move(coffee));
        }
        else
        {
            std::cout << "Invalid condiment type" << std::endl;
            continue;
        }

        coffee->brew();
    }
    return 0;
}
