class Solution
{
public:
    int trap(vector<int> &height)
    {
        int ans = 0;
        int n = height.size();
        stack<pair<int, int>> waterHeight;

        for (int i = 0; i < n; i++)
        {
            int preHeight = 0;
            while (!waterHeight.empty())
            {
                auto stackPoint = waterHeight.top();
                if (height[i] >= stackPoint.first)
                {
                    waterHeight.pop();
                    ans += (i - stackPoint.second - 1) * (stackPoint.first - preHeight);
                    // cout << "i:" << i << " j:" << stackPoint.second << " Height:" << stackPoint.first << " PreHeight:" << preHeight << " ans:" << ans << endl;
                    preHeight = stackPoint.first;
                }
                else
                {
                    ans += (i - stackPoint.second - 1) * (height[i] - preHeight);
                    // cout << "i:" << i << " j:" << stackPoint.second << " Height:" << height[i] << " PreHeight:" << preHeight << " ans:" << ans << endl;
                    break;
                }
            }

            waterHeight.push({height[i], i});
        }

        return ans;
    }
};