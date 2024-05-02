class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        unordered_map<int, int> chmap;
        for (auto ch : s)
        {
            chmap[ch - 'a']++;
        }

        vector<int> ans;
        int thisidx = 0;
        while (thisidx < s.size())
        {
            unordered_map<int, int> thismap;
            int idx = thisidx;
            while (idx < s.size() && !valid(thismap, chmap))
            {
                thismap[s[idx] - 'a']++;
                idx++;
            }
            ans.push_back(idx - thisidx);
            thisidx = idx;
        }
        return ans;
    }

    bool valid(unordered_map<int, int> &thismap, unordered_map<int, int> &chmap)
    {
        if (thismap.size() == 0)
        {
            return false;
        }

        for (auto [key, value] : thismap)
        {
            if (thismap[key] != chmap[key])
            {
                return false;
            }
        }
        return true;
    }
};