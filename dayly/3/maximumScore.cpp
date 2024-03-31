class Solution
{
public:
    int maximumScore(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> left(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && nums[i] <= nums[st.top()])
            {
                st.pop();
            }
            if (!st.empty())
            {
                left[i] = st.top();
            }
            st.push(i);
        }

        vector<int> right(n, n);
        st = stack<int>();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[i] <= nums[st.top()])
            {
                st.pop();
            }
            if (!st.empty())
            {
                right[i] = st.top();
            }
            st.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int h = nums[i], l = left[i], r = right[i];
            if (l < k && k < r)
            {
                ans = max(ans, h * (r - l - 1));
            }
        }
        return ans;
    }
};