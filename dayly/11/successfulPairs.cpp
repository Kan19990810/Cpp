class Solution
{
public:
    int find(int need, vector<int> &potions)
    {
        int l = 0, r = potions.size();
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (potions[mid] >= need)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }

    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        vector<int> pairs;
        sort(potions.begin(), potions.end());

        for (int i = 0; i < spells.size(); i++)
        {
            int need;
            if (success % spells[i] == 0)
            {
                need = success / spells[i];
            }
            else
            {
                need = success / spells[i] + 1;
            }
            if (need > 1e5)
            {
                pairs.push_back(0);
                continue;
            }
            cout << need << endl;
            pairs.push_back(potions.size() - find(need, potions));
        }
        return pairs;
    }
};