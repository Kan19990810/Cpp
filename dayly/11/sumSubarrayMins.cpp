class Solution
{
private:
    static const int MOD = 1e9 + 7;

public:
    int sumSubarrayMins(vector<int> &arr)
    {
        if (arr.size() == 0)
        {
            return 0;
        }

        int n = arr.size();
        vector<int> left(n);
        vector<int> right(n);
        deque<int> stack;
        for (int i = 0; i < n; i++)
        {
            while (!stack.empty() && arr[i] < arr[stack.front()])
            {
                stack.pop_front();
            }
            if (stack.empty())
            {
                left[i] = -1;
            }
            else
            {
                left[i] = stack.front();
            }
            stack.push_front(i);
        }
        stack.clear();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!stack.empty() && arr[i] <= arr[stack.front()])
            {
                stack.pop_front();
            }
            if (stack.empty())
            {
                right[i] = n;
            }
            else
            {
                right[i] = stack.front();
            }
            stack.push_front(i);
        }
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            // cout << ans<<' '<< left[i] <<' '<< right[i] << ' ' <<arr[i]<<endl;
            ans = (ans + (long long)(i - left[i]) * (right[i] - i) * arr[i]) % MOD;
        }
        return ans;
    }
};