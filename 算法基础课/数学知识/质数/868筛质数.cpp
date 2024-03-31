#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000010;

// 质数数组
int primes[N], cnt;

// 是否被筛掉
bool st[N];

// 筛选质数 将质数的倍数筛去
void get_primes(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++)
        {
            // 筛去质数的倍数
            st[primes[j] * i] = true;
            // i 为 primes[j]的倍数停止
            // 防止重复筛 以后会筛到
            if (i % primes[j] == 0)
                break;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    get_primes(n);

    cout << cnt << endl;

    return 0;
}