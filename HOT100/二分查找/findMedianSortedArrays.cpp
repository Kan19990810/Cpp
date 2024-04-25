class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        int left1 = 0, right1 = n - 1;
        int left2 = 0, right2 = m - 1;
        int k = (n + m + 1) >> 1;
        while (k)
        {
            int mid1 = (left1 + right1) >> 1;
            int mid2 = (left2 + right2) >> 1;
            if (nums1[mid1] <= nums2[mid2])
            {
                right2 = mid2;
            }
            else
            {
                right1 = mid1;
            }
        }
    }
};