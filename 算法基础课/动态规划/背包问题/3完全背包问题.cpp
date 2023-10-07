#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int dp[N];
int v[N], w[N];


int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];

    for (int i = 1 ; i<= n; i++)
        for(int j = v[i]; j <= m; j ++)
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);

    cout << dp[m] << endl;

    return 0;
}