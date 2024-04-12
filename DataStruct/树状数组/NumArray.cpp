class NumArray
{
public:
    vector<int> nums;
    vector<int> tree;

    int prefixSum(int x)
    {
        int s = 0;
        for (; x > 0; x -= (x & -x))
        {
            s += tree[x];
        }
        return s;
    }

    NumArray(vector<int> &nums) : nums(nums.size()), tree(nums.size() + 1)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            update(i, nums[i]);
        }
    }

    void update(int index, int val)
    {
        int delta = val - nums[index];
        nums[index] = val;
        for (int i = index + 1; i < tree.size(); i += (i & -i))
        {
            tree[i] += delta;
        }
    }

    int sumRange(int left, int right)
    {
        return prefixSum(right + 1) - prefixSum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */