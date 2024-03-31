#include <unordered_set>
class Solution
{
public:
    int maximumNumberOfStringPairs(vector<string> &words)
    {
        bool seen[26][26]{};
        int ans = 0;
        for (auto &word : words)
        {
            int x = word[0] - 'a';
            int y = word[1] - 'a';
            if (seen[y][x])
            {
                ans++;
            }
            else
            {
                seen[x][y] = true;
            }
        }
        return ans;
    }
};