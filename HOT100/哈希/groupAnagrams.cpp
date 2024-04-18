#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        int n = strs.size();
        unordered_map<string, vector<string>> strMap;
        for (auto str : strs)
        {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            strMap[tmp].push_back(str);
        }
        vector<vector<string>> ans;
        for (pair<string, vector<string>> one : strMap)
        {
            ans.push_back(one.second);
        }
        return ans;
    }
};