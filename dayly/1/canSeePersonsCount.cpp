class Solution
{
public:
    vector<int> canSeePersonsCount(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> ans(n);
        stack<pair<int, int>> st;
        for (int i = 0; i < n; ++i)
        {
            while (!st.empty() && st.top().first < heights[i])
            {
                int tmp = st.top().second;
                ans[tmp] = i - tmp;
                st.pop();
            }
            st.push({heights[i], i});
        }
        while (!st.empty())
        {
            int tmp = st.top().second;
            ans[tmp] = n - tmp - 1;
            st.pop();
        }

        return ans;
    }
};