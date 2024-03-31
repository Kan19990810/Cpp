class Solution
{
public:
    vector<long long> unmarkedSumArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        int m = queries.size();
        // 记录数组总和
        long long numsSum = 0;
        // 记录数组是否被标记过
        vector<bool> st(n, false);
        // 记录数组值和idx
        vector<pair<int, int>> numIdx(n);
        for (int i = 0; i < n; i++)
        {
            numIdx[i] = {nums[i], i};
            numsSum += nums[i];
        }
        sort(numIdx.begin(), numIdx.end());

        // 记录答案
        vector<long long> ans(m, 0);
        // 记录当前在numIdx中的坐标
        int idx = 0;

        for (int i = 0; i < m; i++)
        {
            if (numsSum == 0)
            {
                ans[i] = 0;
                continue;
            }
            int queryIdx = queries[i][0], queryK = queries[i][1];
            // queryIdx没有被标记
            if (st[queryIdx] == false)
            {
                // 将queryIdx标记，在numsSum中减去
                st[queryIdx] = true;
                numsSum -= nums[queryIdx];
            }
            while (queryK)
            {
                // idx 越界，标志着数组全部标记
                if (idx == n || numsSum == 0)
                {
                    ans[i] = 0;
                    break;
                }
                // 当前在numIdx中的数值和对应nums的坐标
                int curValue = numIdx[idx].first, curIdx = numIdx[idx].second;
                if (st[curIdx] == false)
                {
                    st[curIdx] = true;
                    numsSum -= curValue;
                    queryK--;
                }
                idx++;
            }
            // 该查询的操作执行完，记录答案
            ans[i] = numsSum;
        }
        return ans;
    }
};