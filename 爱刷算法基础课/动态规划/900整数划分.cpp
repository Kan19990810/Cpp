#include <iostream>
using namespace std;

const int N = 1010, MOD = 1e9 + 7;
int n;
int dp[N];

int main()
{
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }
    cout << dp[n];
    return 0;
}