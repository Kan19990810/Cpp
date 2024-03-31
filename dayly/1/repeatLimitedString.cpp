class Solution
{
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        vector<int> alphaCount(26, 0);
        for (auto &str : s)
        {
            alphaCount[str - 'a']++;
        }
        string ans;
        int i = 25;
        int sameCount = 0;
        while (i >= 0)
        {
            if (alphaCount[i] > 0 && sameCount < repeatLimit)
            {
                ans += 'a' + i;
                alphaCount[i]--;
                sameCount++;
                // cout << 1 << ' ' << ans << ' ' << i << " " << alphaCount[i] << ' ' << sameCount << endl;
            }
            else if (alphaCount[i] == 0)
            {
                i--;
                sameCount = 0;
                // cout << 2 << ' ' << ans << ' ' << i << " " << alphaCount[i] << ' ' << sameCount << endl;
            }
            else if (sameCount == repeatLimit)
            {
                // 往前搜索一个字符
                int j = i - 1;
                bool isFind = false;
                while (j >= 0 && !isFind)
                {
                    if (alphaCount[j] == 0)
                    {
                        j--;
                    }
                    else if (alphaCount[j] > 0)
                    {
                        ans += 'a' + j;
                        alphaCount[j]--;
                        sameCount = 0;
                        isFind = true;
                        // cout << 3 << ' ' << ans << ' ' << j << " " << alphaCount[j] << ' ' << sameCount << endl;
                    }
                }
                if (!isFind)
                {
                    return ans;
                }
            }
        }
        return ans;
    }
};