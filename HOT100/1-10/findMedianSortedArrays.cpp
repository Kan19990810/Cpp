class Solution
{
public:
    int getKthElement(const vector<int> &nums1, const vector<int> &nums2, int k)
    {
        int n = nums1.size();
        int m = nums2.size();
        int idx1 = 0, idx2 = 0;
        while (true)
        {
            if (idx1 == n)
            {
                return nums2[idx2 + k - 1];
            }
            if (idx2 == m)
            {
                return nums1[idx1 + k - 1];
            }
            if (k == 1)
            {
                return min(nums1[idx1], nums2[idx2]);
            }

            // [idx, idx1 + k / 2 - 1] 有 k / 2个元素，每次k范围减少一半
            int newIdx1 = min(idx1 + k / 2 - 1, n - 1);
            int newIdx2 = min(idx2 + k / 2 - 1, m - 1);
            int p1 = nums1[newIdx1];
            int p2 = nums2[newIdx2];

            if (p1 <= p2)
            {
                k -= newIdx1 - idx1 + 1;
                idx1 = newIdx1 + 1;
            }
            else
            {
                k -= newIdx2 - idx2 + 1;
                idx2 = newIdx2 + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int totalLength = nums1.size() + nums2.size();
        // 奇数个取第 （totalLength + 1）/ 2个
        if (totalLength % 2 == 1)
        {
            return getKthElement(nums1, nums2, (totalLength + 1) / 2);
        }
        // 偶数个取第 totalLength / 2 和（totalLength + 1）/ 2 平均值
        else
        {

            return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
        }
    }
};