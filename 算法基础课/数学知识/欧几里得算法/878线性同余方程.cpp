#include <iostream>
#include <algorithm>

typedef long long LL;

using namespace std;

int exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y , x);
    y -= a / b * x;
    return d;
}

int main()
{
    int n, x, y, a, b, m;
    cin >> n;
    while (n --)
    {
        cin >> a >> b >> m;
        int d = exgcd(a, m, x , y);
        if (b % d) puts("impossible");
        else cout << (LL) x * (b / d) % m << endl;
    }
    return 0;
}