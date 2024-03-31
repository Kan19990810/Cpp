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

    while(n --)
    {
        int x;
        cin >> x;
        for(int i =2; i <= x / i; i++)
        {
            while(x % i == 0)
            {
                x /= i;
                primes[i] += 1;
            }
        }
        if (x > 1) primes[x] += 1;
    }

    LL res =1;
    // STL 可以这么遍历哈希表 ， prime.first -> key   prime.second -> value
    for(auto prime: primes)
    {
        int p = prime.first, a = prime.second;
        LL t = 1;
        while(a--)
        {
            t = (t * p + 1) % N;
        }
        res = res * t % N;
    }

    cout << res << endl;

    return 0;
}