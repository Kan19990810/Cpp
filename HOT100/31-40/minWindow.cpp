class Solution
{
public:
    string minWindow(string s, string t)
    {
        // t中的字符集合
        unordered_set<char> tSet;
        // t中字符对应的个数
        unordered_map<char, int> tMap;
        for (auto chr : t)
        {
            tSet.emplace(chr);
            tMap[chr] += 1;
        }
        // chrNum 为需要统计的字符
        int n = s.size();
        int chrNum = tSet.size();
        string ans = "";
        int minLength = INT_MAX;
        int st = 0, ed = 0;
        for (; ed < n; ed++)
        {
            // st移动到不符合条件
            while (chrNum == 0)
            {
                if (tSet.count(s[st]) != 0)
                {
                    tMap[s[st]]++;
                    if (tMap[s[st]] > 0)
                    {
                        chrNum++;
                    }
                }
                st++;
            }
            // 不符合条件的时候
            // 如果当前位置的字符不需要则st++
            // tSet中没有该字符则不需要，tMap中该字符 <0 也不需要
            while (st < ed && chrNum > 0)
            {
                if (tSet.count(s[st]) == 0)
                {
                    st++;
                    continue;
                }
                if (tMap[s[st]] < 0)
                {
                    tMap[s[st]]++;
                    st++;
                    continue;
                }
                break;
            }
            // 如果字符在t中出现，进行处理
            if (tSet.count(s[ed]) != 0)
            {
                tMap[s[ed]]--;
                // 个数首次到达0时， 需要统计的字符数减1
                // tMap[s[ed]] 可小于 0
                if (tMap[s[ed]] == 0)
                {
                    chrNum--;
                    if (chrNum == 0 && (ed - st + 1) < minLength)
                    {
                        minLength = ed - st + 1;
                        ans = s.substr(st, ed - st + 1);
                    }
                }
                cout << "st:" << st << " ed:" << ed << " s[ed]:" << s[ed] << " tMap:" << tMap[s[ed]] << " chrNum:" << chrNum << " minLength:" << minLength << " ans:" << ans << endl;
            }
        }

        while (chrNum == 0)
        {
            if (tSet.count(s[st]) != 0)
            {
                tMap[s[st]]++;
                if (tMap[s[st]] > 0)
                {
                    chrNum++;
                }
                if (chrNum == 0 && (ed - st + 1) < minLength)
                {
                    minLength = ed - st + 1;
                    ans = s.substr(st, ed - st + 1);
                }
            }
            st++;
        }

        return ans;
    }
};