#include <iostream>
#include <string>

class Chair
{
public:
    virtual void showInfo() = 0;
};

class ModernChair : public Chair
{
public:
    void showInfo() override
    {
        std::cout << "modern chair" << std::endl;
    }
};

class ClassicalChair : public Chair
{
public:
    void showInfo() override
    {
        std::cout << "classical chair" << std::endl;
    }
};

class Sofa
{
public:
    virtual void displayInfo() = 0;
};

class ModernSofa : public Sofa
{
public:
    void displayInfo() override
    {
        std::cout << "modern sofa" << std::endl;
    }
};

class ClassicalSofa : public Sofa
{
public:
    void displayInfo() override
    {
        std::cout << "classical sofa" << std::endl;
    }
};

class FurnitureFactory
{
public:
    virtual Chair *createChair() = 0;
    virtual Sofa *createSofa() = 0;
};

class ModernFurnitureFactory : public FurnitureFactory
{
public:
    Chair *createChair() override
    {
        return new ModernChair();
    }

    Sofa *createSofa() override
    {
        return new ModernSofa();
    }
};

class ClassicalFurnitureFactory : public FurnitureFactory
{
public:
    Chair *createChair() override
    {
        return new ClassicalChair();
    }

    Sofa *createSofa() override
    {
        return new ClassicalSofa();
    }
};

int main()
{
    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::string furnitureType;
        std::cin >> furnitureType;

        FurnitureFactory *factory = nullptr;
        if (furnitureType == "modern")
        {
            factory = new ModernFurnitureFactory();
        }
        else if (furnitureType == "classical")
        {
            factory = new ClassicalFurnitureFactory();
        }

        Chair *chair = factory->createChair();
        Sofa *sofa = factory->createSofa();

        chair->showInfo();
        sofa->displayInfo();

        delete chair;
        delete sofa;
        delete factory;
    }
    return 0;
}