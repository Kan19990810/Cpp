#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;

int pmi(int a, int k, int p)
{
    // 将 k 进行二进制分解
    LL res = 1;
    while (k)
    {
        if (k & 1)
        {
            res = res * a % p;
        }
        k = k >> 1;
        a = (LL)a * a % p;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, k, p;
        cin >> a >> k >> p;
        cout << pmi(a, k, p) << endl;
    }
    return 0;
}