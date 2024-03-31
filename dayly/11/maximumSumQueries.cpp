class Solution
{
public:
    vector<int> maximumSumQueries(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &queries)
    {
        // {nums1, nums2} 有序排列
        vector<pair<int, int>> a(nums1.size());
        for (int i = 0; i < nums1.size(); i++)
        {
            a[i] = {nums1[i], nums2[i]};
        }
        sort(a.begin(), a.end(),
             [](auto &a, auto &b)
             { return a.first > b.first; });

        // queries 有序排列下标
        vector<int> qid(queries.size());
        iota(qid.begin(), qid.end(), 0);
        sort(qid.begin(), qid.end(),
             [&](int i, int j)
             { return queries[i][0] > queries[j][0]; });

        // 答案
        vector<int> ans(queries.size());
        // 单调栈，主键： first -> nums2, second -> sum, 存所有符合当前queryde的情况
        //  nums2的升序， sum 的降序
        vector<pair<int, int>> st;
        int j = 0;
        // 遍历从 xi大的query开始
        for (int i : qid)
        {
            int x = queries[i][0], y = queries[i][1];
            // 从所有nums1满足条件中选择
            for (; j < a.size() && a[j].first >= x; j++)
            { // 下面只需关心 a[j].second
                while (!st.empty() && st.back().second <= a[j].first + a[j].second)
                { // a[j].second >= st.back().first
                    st.pop_back();
                }
                if (st.empty() || st.back().first < a[j].second)
                {
                    st.emplace_back(a[j].second, a[j].first + a[j].second);
                }
            }
            // 找到一个的大于等于 query.second , 此时对应 sum 最大
            auto it = lower_bound(st.begin(), st.end(), y,
                                  [](const auto &p, int val)
                                  { return p.first < val; });
            ans[i] = it != st.end() ? it->second : -1;
        }
        return ans;
    }
};
