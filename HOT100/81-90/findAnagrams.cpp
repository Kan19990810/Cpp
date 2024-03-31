class Solution
{
public:
    bool isValid(unordered_map<char, int> &pMap, unordered_map<char, int> &sMap)
    {
        for (auto t : pMap)
        {
            char key = t.first;
            int value = t.second;
            if (sMap[key] != value)
            {
                return false;
            }
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p)
    {
        unordered_map<char, int> pMap;
        unordered_map<char, int> sMap;
        for (auto chr : p)
        {
            pMap[chr]++;
        }

        for (int i = 0; i < p.size(); i++)
        {
            sMap[s[i]]++;
        }

        vector<int> ans;
        for (int i = p.size(); i < s.size(); i++)
        {
            if (isValid(pMap, sMap))
            {
                ans.push_back(i - p.size());
            }

            sMap[s[i - p.size()]]--;
            sMap[s[i]]++;
        }

        if (isValid(pMap, sMap))
        {
            ans.push_back(s.size() - p.size());
        }

        return ans;
    }
};