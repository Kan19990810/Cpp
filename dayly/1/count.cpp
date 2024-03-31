class Solution
{
public:
    static const int MOD = 1e9 + 7;
    int cal(string &s, int minSum, int maxSum)
    {
        int n = s.length();
        vector<vector<int>> memo(n, vector<int>(min(9 * n, maxSum) + 1, -1));
        function<int(int, int, bool)> dfs = [&](int i, int sum, bool isLimit)
        {
            if (sum > maxSum)
            {
                return 0;
            }
            if (i == n)
            {
                return sum > minSum ? 1 : 0;
            }
            if (!isLimit && memo[i][sum] != -1)
            {
                return memo[i][sum];
            }
            int up = isLimit ? s[i] - '0' : 9;
            int res = 0;
            for (int d = 0; d <= up; d++)
            {
                res = (res + dfs(i + 1, sum + d, isLimit && d == up)) % MOD;
            }

            if (!isLimit)
            {
                memo[i][sum] = res;
            }
            return res;
        };
        return dfs(0, 0, true);
    }

    int count(string num1, string num2, int min_sum, int max_sum)
    {
        int ans = calc(num2, min_sum, max_sum) - calc(num1, min_sum, max_sum);
        int sum = 0;
        for (char c : num1)
        {
            sum += c - '0';
        }
        ans += min_sum <= sum && sum <= max_sum;
        return ans % MOD;
    }
};