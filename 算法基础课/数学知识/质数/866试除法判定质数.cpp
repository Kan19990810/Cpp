#include <iostream>

using namespace std;

const int N = 110;
int n, a[N];

bool is_prime(int x)
{
    // 从[2, √x]试除
    if (x < 2)
        return false;
    for (int i = 2; i <= x / i; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (is_prime(a[i]))
            puts("Yes");
        else
            puts("No");
    }

    return 0;
}