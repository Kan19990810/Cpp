class Solution
{
public:
    int maximumLength(string s)
    {
        // 统计各个字母的长度
        int n = s.size();
        int i = 0, pre = 0;
        vector<vector<int>> alpha_length(26);
        while (i < n)
        {
            if (s[pre] == s[i])
            {
                i++;
            }
            else
            {
                alpha_length[s[pre] - 'a'].push_back(i - pre);
                pre = i;
                i++;
            }
        }
        alpha_length[s[pre] - 'a'].push_back(i - pre);

        // "aaa" = 1,"aa" "aa" = 1, "aa" "a" = 1, "a" "a" "a" = 1
        int ans = 0;
        // 26 *
        for (auto &each_alpha : alpha_length)
        {
            int res = 0;
            int m = each_alpha.size();
            int pre_alpha = 0;
            sort(each_alpha.begin(), each_alpha.end());
            for (int j = 0; j < m; j++)
            {
                res = max(res, each_alpha[j] - 2);
                if (j > 0 && each_alpha[j] == each_alpha[j - 1] + 1)
                {
                    res = max(res, each_alpha[j - 1]);
                }
                if (j > 0 && each_alpha[j] == each_alpha[j - 1])
                {
                    res = max(res, each_alpha[j - 1] - 1);
                }
                if (j > 1 && each_alpha[j] == each_alpha[j - 2])
                {
                    res = max(res, each_alpha[j - 2]);
                }
            }
            ans = max(ans, res);
        }

        if (ans == 0)
        {
            return -1;
        }
        return ans;
    }
};