#include <iostream>
#include <vector>
#include <algorithm>

class Observer
{
public:
    virtual void update(int hour) = 0;
    virtual ~Observer() = default;
};

class Subject
{
public:
    virtual void registerObserver(Observer *observer) = 0;
    virtual void removeObserver(Observer *observer) = 0;
    virtual void notifyObservers() = 0;
    virtual ~Subject() = default;
};

class Clock : public Subject
{
private:
    std::vector<Observer *> observers;
    int hour;

public:
    Clock() : hour(0)
    {
    }
    void registerObserver(Observer *observer) override
    {
        observers.push_back(observer);
    }

    void removeObserver(Observer *observer) override
    {
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end())
        {
            observers.erase(it);
        }
    }

    void notifyObservers() override
    {
        for (Observer *observer : observers)
        {
            observer->update(hour);
        }
    }

    const std::vector<Observer *> &getObservers() const
    {
        return observers;
    }

    void tick()
    {
        hour = (hour + 1) % 24;
        notifyObservers();
    }
};

class Student : public Observer
{
private:
    std::string name;

public:
    Student(const std::string &name) : name(name)
    {
    }
    void update(int hour) override
    {
        std::cout << name << " " << hour << std::endl;
    }
};

int main()
{
    int N;
    std::cin >> N;

    Clock clock;

    for (int i = 0; i < N; i++)
    {
        std::string studentName;
        std::cin >> studentName;
        clock.registerObserver(new Student(studentName));
    }

    int updates;
    std::cin >> updates;

    for (int i = 0; i < updates; i++)
    {
        clock.tick();
    }

    for (Observer *observer : clock.getObservers())
    {
        delete observer;
    }
    return 0;
}
