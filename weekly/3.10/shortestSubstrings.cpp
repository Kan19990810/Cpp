class Solution
{
private:
    // void dfs(string curArr, string arr, int idx, unordered_set<string> &arrSet)
    // {
    //     // 终止条件
    //     if (idx == arr.size())
    //     {
    //         return;
    //     }

    //     // 不放入当前字符
    //     dfs(curArr, arr, idx + 1, arrSet);

    //     // 放入当前字符
    //     curArr += arr[idx];
    //     // 集合中没有该子字符串则放入集合
    //     if (arrSet.count(curArr) == 0)
    //     {
    //         arrSet.emplace(curArr);
    //     }
    //     dfs(curArr, arr, idx + 1, arrSet);
    //     // curArr -= arr[idx];
    // }

public:
    vector<string> shortestSubstrings(vector<string> &arr)
    {
        int n = arr.size();
        vector<string> ans(n);

        vector<unordered_set<string>> arrSet(n);

        // 遍历求出所有字符串的子串
        for (int i = 0; i < n; i++)
        {
            // dfs(arr[i], arrSet[i]);

            int m = arr[i].size();
            for (int k = 0; k < m; k++)
            {
                for (int t = 1; t + k <= m; t++)
                {
                    string tmpStr = arr[i].substr(k, t);
                    if (arrSet[i].count(tmpStr) == 0)
                    {
                        arrSet[i].emplace(tmpStr);
                    }
                }
            }
        }

        // 遍历所有字符串
        for (int i = 0; i < n; i++)
        {
            // 遍历字符串的所有子串
            for (auto &subarr : arrSet[i])
            {
                bool is_valid = true;
                // 遍历其他字符串
                for (int j = 0; j < n; j++)
                {
                    if (i == j)
                    {
                        continue;
                    }
                    // 查看子串是否在其他字符串中出现
                    if (arrSet[j].count(subarr) != 0)
                    {
                        is_valid = false;
                        break;
                    }
                }
                // 子串合理，则更新答案
                if (is_valid)
                {
                    // 如果当前答案不存在则直接插入
                    if (ans[i] == "")
                    {
                        ans[i] = subarr;
                    }
                    // 最短字符串且字典序最小
                    else
                    {
                        // 长短小于当前答案
                        if (subarr.size() < ans[i].size())
                        {
                            ans[i] = subarr;
                        }
                        // 长短相同但是字典序小
                        if (subarr.size() == ans[i].size() and subarr.compare(ans[i]) < 0)
                        {
                            ans[i] = subarr;
                        }
                    }
                }
            }
        }
        return ans;
    }
};