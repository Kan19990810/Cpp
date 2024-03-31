class Solution
{
public:
    long long maximumSumOfHeights(vector<int> &maxHeights)
    {
        int pre = -1, n = maxHeights.size();
        long long res = 0;
        bool rise = true;
        for (int i = 0; i < n; i++)
        {
            if (rise && maxHeights[i] < pre)
            {
                rise = false;

                long long ans = 0;
                int m = maxHeights[i - 1];
                for (int j = i - 1; j >= 0; j--)
                {
                    m = min(m, maxHeights[j]);
                    ans += m;
                }
                m = maxHeights[i - 1];
                for (int j = i; j < n; j++)
                {
                    m = min(m, maxHeights[j]);
                    ans += m;
                }
                res = max(res, ans);
            }
            if (maxHeights[i] >= pre)
            {
                rise = true;
            }
            // cout << pre << ' ' << maxHeights[i] << ' ' << rise << ' ' << res << endl;
            pre = maxHeights[i];
        }

        long long ans = 0;
        int m = maxHeights[n - 1];
        for (int j = n - 1; j >= 0; j--)
        {
            m = min(m, maxHeights[j]);
            ans += m;
        }
        res = max(res, ans);

        return res;
    }
};