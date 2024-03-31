class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        // 记录最大元素的出现的位置
        vector<int> loc;
        int ma = 0, n = nums.size();
        long long res = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > ma)
            {
                ma = nums[i];
                loc.clear();
                loc.push_back(i);
            }
            else if (nums[i] == ma)
            {
                loc.push_back(i);
            }
            // cout << i << ' ' <<ma << ' '<< loc.size()<<endl;
        }
        // 特判个数不足的情况
        if (loc.size() < k)
        {
            return 0;
        }
        // t 为出现次数， t - (t + 1) + (t + 2) ...
        // 遍历loc, 满足的情况为[i, i + k - 1], (loc[i] - 0 + 1) * (n - 1 - (loc[i + k - 1] ) + 1)
        // int re = 1;
        // for (int t = k; t <= loc.size(); t++)
        // {
        //     for (int i = 0; i + t - 1 < loc.size(); i++)
        //     {
        //         res += re * (loc[i] + 1) * (n - loc[i + t - 1]);
        //         cout << t << ' '  << i << ' ' << i + t - 1 << ' ' << loc[i] + 1 << ' ' << n - loc[i + t - 1] << ' '  <<re * (loc[i] + 1) * (n - loc[i + t - 1]) << ' ' << res << endl;
        //     }
        //     re *= -1;
        // }
        for (int i = 0; i + k - 1 < loc.size(); i++)
        {
            res += (long long)(loc[i] + 1) * (n - loc[i + k - 1]);
            // cout << t << ' '  << i << ' ' << i + t - 1 << ' ' << loc[i] + 1 << ' ' << n - loc[i + t - 1] << ' '  <<re * (loc[i] + 1) * (n - loc[i + t - 1]) << ' ' << res << endl;
        }
        if (k + 1 <= loc.size())
        {
            int t = k + 1;
            for (int i = 0; i + t - 1 < loc.size(); i++)
            {
                res += (long long)(-1) * (loc[i] + 1) * (n - loc[i + t - 1]);
                // cout << t << ' '  << i << ' ' << i + t - 1 << ' ' << loc[i] + 1 << ' ' << n - loc[i + t - 1] << ' '  <<re * (loc[i] + 1) * (n - loc[i + t - 1]) << ' ' << res << endl;
            }
        }
        return res;
    }
};