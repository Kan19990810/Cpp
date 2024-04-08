class Solution
{
public:
    vector<int> nums;
    vector<int> tree;

    void update(int x)
    {
        for (int i = x + 1; i < tree.size(); i += (i & -i))
        {
            tree[i]++;
        }
    }

    int query(int x)
    {
        int s = 0;
        for (; x > 0; x &= x - 1)
        {
            s += tree[x];
        }
        return s;
    }

    vector<int> countSmaller(vector<int> &nums)
    {
        vector<int> res;
        tree.resize(20010);

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            res.push_back(query(nums[i] + 10000));
            update(nums[i] + 10000);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};