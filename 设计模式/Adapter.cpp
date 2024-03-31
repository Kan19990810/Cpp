#include <iostream>

class USB
{
public:
    virtual void charge() = 0;
};

class TypeC
{
public:
    virtual void chargeWithTypeC() = 0;
};

class TypeCAdapter : public USB
{
private:
    TypeC *typeC;

public:
    TypeCAdapter(TypeC *typeC) : typeC(typeC)
    {
    }

    void charge() override
    {
        typeC->chargeWithTypeC();
    }
};

class NewComputer : public TypeC:
{
public:
    void chargeWithTypeC() override
    {
        std::cout << "TypeC" << std::endl;
    }
};

class AdapterCharger : public USB
{
public:
    void charge() override
    {
        std::cout << "USB Adapter" << std::endl;
    }
};

int main()
{
    int N;

    std::cin >> N;
    std::cin.ignore();
    for (int i = 0; i < N; i++)
    {
        int choice;
        std::cin >> choice;

        if (choice == 1)
        {
            TypeC *newComputer = new NewComputer();
            newComputer->chargeWithTypeC();
            delete newComputer;
        }
        else if (choice == 2)
        {
            USB *usbAdapter = new AdapterCharger();
            usbAdapter->charge();
            delete usbAdapter;
        }
    }
    return 0;
}