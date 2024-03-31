#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    unordered_map<int, int> primes;

    // 约数的个数 分解质因数 记录个数
    while (n--)
    {
        int x;
        cin >> x;
        for (int i = 2; i <= x / i; i++)
        {
            while (x % i == 0)
            {
                x /= i;
                primes[i] += 1;
            }
        }
        if (x > 1)
            primes[x] += 1;
    }

    LL res = 1;
    // STL 可以这么遍历哈希表 ， prime.first -> key   prime.second -> value
    for (auto prime : primes)
    {
        // 选或不选
        res = res * (prime.second + 1) % N;
    }

    cout << res << endl;

    return 0;
}