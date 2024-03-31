#include <iostream>
using namespace std;

const int N = 1010;

int n, res = 0;
;
int a[N], dp[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (a[i] > a[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        res = max(res, dp[i]);
    }

    cout << res << endl;
    return 0;
}
