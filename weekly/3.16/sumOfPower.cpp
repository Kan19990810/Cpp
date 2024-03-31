class Solution
{
private:
    static const int MOD = 1e9 + 7;

public:
    int sumOfPower(vector<int> &nums, int k)
    {
        int ans = 0;
        long long dp[101][101][101];
        int n = nums.size();
        dp[0][0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                for (int k = 0; k <= n; k++)
                {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j >= nums[i - 1] && k > 0)
                    {
                        dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - nums[i - 1]][k - 1]) % MOD;
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            // cout << i << ' ' << dp[n][k][i] << endl;
            int t = (long long)dp[n][k][i] * (long long)pmi(2, n - i) % MOD;
            ans = ((long long)ans + t) % MOD;
        }
        return ans;
    }

    int pmi(int a, int k)
    {
        // 将 k 进行二进制分解
        long long res = 1;
        while (k)
        {
            if (k & 1)
            {
                res = res * a % MOD;
            }
            k = k >> 1;
            a = (long long)a * a % MOD;
        }
        return res;
    }
};