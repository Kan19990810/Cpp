#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int res = 0;

    cin >> n;

    while (n --)
    {
        int x;
        cin >> x;
        res ^= x;
    }

    if (res) puts("Yes");
    else puts("No");

    return 0;
}