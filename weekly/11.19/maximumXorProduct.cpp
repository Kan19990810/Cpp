class Solution
{
public:
    int maximumXorProduct(long long a, long long b, int n)
    {
        static const int MOD = 1e9 + 7;

        long long cur_a = (a >> n) ^ 0, cur_b = (b >> n) ^ 0;
        for (int i = 1; i <= n; i++)
        {
            int a_num = a >> (n - i) & 1;
            int b_num = b >> (n - i) & 1;
            if (a_num == b_num)
            {
                cur_a = (cur_a << 1) + 1;
                cur_b = (cur_b << 1) + 1;
            }
            else if (cur_a <= cur_b)
            {
                cur_a = (cur_a << 1) + 1;
                cur_b = cur_b << 1;
            }
            else
            {
                cur_a = cur_a << 1;
                cur_b = (cur_b << 1) + 1;
            }
        }
        // cout << cur_a << ' ' <<cur_b<<endl;
        // long long res = cur_a * cur_b % MOD;
        unsigned long long res = (unsigned long long)cur_a * cur_b;

        // cout << res << endl;
        cur_a = (a >> n) ^ 0;
        cur_b = (b >> n) ^ 0;
        for (int i = 1; i <= n; i++)
        {
            int a_num = a >> (n - i) & 1;
            int b_num = b >> (n - i) & 1;
            if (a_num == b_num)
            {
                cur_a = (cur_a << 1) + 1;
                cur_b = (cur_b << 1) + 1;
            }
            else if (cur_a < cur_b)
            {
                cur_a = (cur_a << 1) + 1;
                cur_b = cur_b << 1;
            }
            else
            {
                cur_a = cur_a << 1;
                cur_b = (cur_b << 1) + 1;
            }
        }
        res = max(res, (unsigned long long)cur_a * cur_b);
        // cout << res << endl;
        res %= MOD;
        return (long long)res;

        // static const int N = 52;
        // int dp[N][2];

        // for (int i = 1; i <= 50; i++)
        // {
        //     int a_num = a >> (50 - i) & 1;
        //     int b_num = b >> (50 - i) & 1;
        //     dp[i][0] = (dp[i - 1][0] << 1 + a_num ^ 0) * (d)
        // }
    }
};