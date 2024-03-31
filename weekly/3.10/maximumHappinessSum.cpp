class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        sort(happiness.begin(), happiness.end(), [&](int x, int y)
             { return x > y; });

        long long ans = 0;
        int n = happiness.size();
        for (int i = 0; i < k; i++)
        {
            if (happiness[i] - i <= 0)
            {
                break;
            }
            ans += (long long)happiness[i] - i;
        }

        return ans;
    }
};