class Solution
{
public:
    long long minimumRemoval(vector<int> &beans)
    {
        sort(beans.begin(), beans.end());

        long long total = 0;
        for (auto &bean : beans)
        {
            total += bean;
        }

        int n = beans.size();
        long long ans = total;
        for (int i = 0; i < n; ++i)
        {
            ans = min(ans, total - (long long)beans[i] * (n - i));
        }
        return ans;
    }
};