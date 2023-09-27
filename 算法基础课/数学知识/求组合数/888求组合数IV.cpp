#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

LL p;

int pmi(int a, int k, int p)
{
    int res = 1;
    while (k)
    {
        if( k & 1) res = (LL) res * a % p;
        a = (LL) a * a % p;
        k = k >> 1;
    }

    return res; 
}

LL c(int a, int b)
{
    int res = 1;
    for(int i = 1, j = a; i <= b; i++, j--)
    {
        res = (LL) res * j % p;
        res = (LL) res * pmi(i, p - 2, p) % p;
    }
    return res;
}

LL lucas(LL a, LL b)
{
    if(a < p && b < p) return c(a, b);
    else return (LL) c(a % p, b % p) * lucas(a / p, b / p) % p;
}

int main()
{
    int n;
    cin >> n;

    while (n --)
    {
        LL a, b;
        cin >> a >> b >> p;
        cout << lucas(a, b) << endl;
    }

    return 0;
}