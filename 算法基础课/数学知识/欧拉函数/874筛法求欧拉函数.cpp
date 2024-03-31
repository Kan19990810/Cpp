#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000010;

typedef long long LL;

int primes[N], cnt;
// phi记录欧拉函数
int phi[N];
bool st[N];

// 结合筛质数方法
LL get_euler(int n)
{
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            primes[cnt++] = i;
            // 质数 互质的数为i - 1个
            phi[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j++)
        {
            // 非质数
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
            {
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            }
            phi[i * primes[j]] = phi[i] * (primes[j] - 1);
        }
    }
    LL res = 0;
    for (int i = 1; i <= n; i++)
        res += phi[i];
    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << get_euler(n) << endl;
    return 0;
}