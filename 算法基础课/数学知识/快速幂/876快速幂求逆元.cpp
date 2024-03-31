#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;

int pmi(int a, int k, int p)
{
    LL res = 1;
    while(k)
    {
        if(k & 1)
        {
            res = res * a % p;
        }
        k = k >> 1;
        a = (LL) a * a % p;
    }
    return res;
}


int main()
{
    int n;
    cin >> n;
    while (n --)
    {
        int a, p;
        cin >> a >> p;
        LL res = pmi(a, p - 2, p);
        if (a % p) cout << res << endl;
        else    puts("impossible");
    }
    return 0;
}