class Solution
{
public:
    string minimizeStringValue(string s)
    {
        int n = s.size();
        vector<int> chrNum(26, 0);
        // c 为 问号出现的次数
        int c = 0;
        // 统计所有字符出现的次数
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '?')
            {
                c++;
                continue;
            }
            chrNum[s[i] - 'a']++;
        }

        vector<int> useNum(26, 0);
        // 找出填写的字母
        for (int i = 1; i <= c; i++)
        {
            // 找到出现次数最小的字符
            int minNum = chrNum[0];
            int idx = 0;
            for (int j = 1; j < 26; j++)
            {
                if (chrNum[j] < minNum)
                {
                    minNum = chrNum[j];
                    idx = j;
                }
            }
            useNum[idx]++;
            chrNum[idx]++;
        }

        // 从小的字母开始填写
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '?')
            {
                for (int j = 0; j < 26; j++)
                {
                    if (useNum[j] != 0)
                    {
                        s[i] = 'a' + j;
                        useNum[j]--;
                        break;
                    }
                }
            }
        }
        return s;
    }
};