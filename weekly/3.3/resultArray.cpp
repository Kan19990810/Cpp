class Solution
{
public:
    vector<int> resultArray(vector<int> &nums)
    {
        vector<int> nums1;
        vector<int> nums2;
        int n = nums.size();
        int i = 0;
        int n1, n2;
        while (i < n)
        {
            if (i == 0)
            {
                n1 = nums[i++];
                nums1.push_back(n1);
                continue;
            }
            if (i == 1)
            {
                n2 = nums[i++];
                nums2.push_back(n2);
                continue;
            }

            if (n1 > n2)
            {
                n1 = nums[i++];
                nums1.push_back(n1);
            }
            else
            {
                n2 = nums[i++];
                nums2.push_back(n2);
            }
        }
        for (auto &num : nums2)
        {
            nums1.push_back(num);
        }
        return nums1;
    }
};