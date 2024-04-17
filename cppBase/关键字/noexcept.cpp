#include <iostream>
using namespace std;

// move if noexpect

void printMessage()
{
    cout << "Hello World!" << endl;
    exit(0);
}

void execute() noexcept
{
    if (noexcept(execute()))
        throw "Ha!";
}

int main()
{
    set_terminate(&printMessage);
    execute();
}