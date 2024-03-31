class Solution
{
public:
    int minimumDeletions(string word, int k)
    {
        vector<int> numCount(26, 0);
        for (auto c : word)
        {
            numCount[c - 'a']++;
        }
        sort(numCount.begin(), numCount.end());
        int ans = word.size();
        for (int i = 0; i < 26; i++)
        {
            // cout << numCount[i] << endl;
            if (numCount[i] == 0)
            {
                continue;
            }
            int res = 0;
            int up = numCount[i] + k;
            for (int j = 0; j < 26; j++)
            {
                if (numCount[j] == 0)
                {
                    continue;
                }
                if (numCount[j] < numCount[i])
                {
                    res += numCount[j];
                }
                else if (numCount[j] > up)
                {
                    res += numCount[j] - up;
                }

                // cout << "i:" << i << " j:" << j << " numCount[i]:" << numCount[i] << " up:" << up << " numCount[j]:" << numCount[j] << " ans:" << ans << endl;
            }
            ans = min(ans, res);
        }
        return ans;
    }
};