class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        // i 左侧第一个低于heights[i]
        // i 右侧第一个低于heights[i]
        int n = heights.size();
        vector<int> lowLeft(n);
        vector<int> lowRight(n);
        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && heights[s.top()] > heights[i])
            {
                lowRight[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }

        while (!s.empty())
        {
            lowRight[s.top()] = n;
            s.pop();
        }

        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && heights[s.top()] > heights[i])
            {
                lowLeft[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }

        while (!s.empty())
        {
            lowLeft[s.top()] = -1;
            s.pop();
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, heights[i] * (lowRight[i] - lowLeft[i] - 1));
        }
        return ans;
    }
};