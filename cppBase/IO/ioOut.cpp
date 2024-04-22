#include <iostream>
#include <charconv>
#include <string.h>
using namespace std;

int main()
{
    // {
    //     const char *test = "hello here\n";
    //     cout.write(test, strlen(test));
    // }

    // {
    //     cout.put('a');
    // }

    // {
    //     cout << "abc";
    //     cout.flush();
    // }

    {
        cout.flush();
        if (!cout)
        {
            cerr << "unable to flush \n";
        }
    }

    return 0;
}