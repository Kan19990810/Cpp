class Solution
{
public:
    int minimumBoxes(vector<int> &apple, vector<int> &capacity)
    {
        int appleNum = accumulate(apple.begin(), apple.end(), 0);

        int n = capacity.size();
        int ans = 0;
        sort(capacity.begin(), capacity.end(), [&](int x, int y)
             { return x > y; });
        for (int i = 0; i < n; i++)
        {
            if (appleNum <= 0)
            {
                break;
            }
            appleNum -= capacity[i];
            ans++;
        }

        return ans;
    }
};