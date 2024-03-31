class NumArray
{
public:
    NumArray(vector<int> &nums)
    {
        nums_ = nums;
    }

    void update(int index, int val)
    {
        nums_[index] = val;
    }

    int sumRange(int left, int right)
    {
        int res = 0;
        for (int i = left; i <= right; i++)
        {
            res += nums_[i];
        }
        return res;
    }

private:
    vector<int> nums_;
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */