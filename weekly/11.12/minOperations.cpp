class Solution
{
public:
    int minOperations(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        bool valid = true;
        int res = 1010;
        int ans = 0;
        int back_1 = nums1.back();
        int back_2 = nums2.back();
        for (int i = 0; i < n - 1; i++)
        {
            if ((nums1[i] > back_1 && nums1[i] > back_2) || (nums2[i] > back_1 && nums2[i] > back_2) || (nums1[i] > back_1 && nums2[i] > back_1) || (nums1[i] > back_2 && nums2[i] > back_2))
            {
                valid = false;
                break;
            }
            if (nums1[i] > back_1 && nums1[i] <= back_2 && nums2[i] <= back_1)
            {
                ans++;
            }
            if (nums2[i] > back_2 && nums2[i] <= back_1 && nums1[i] <= back_2)
            {
                ans++;
            }
            // cout << i << ' ' << ans << endl;
        }
        if (valid)
        {
            res = min(res, ans);
        }
        // cout << res << endl;

        valid = true;
        ans = 1;
        back_1 = nums2.back();
        back_2 = nums1.back();
        // cout << back_1 << ' ' << back_2 <<endl;
        for (int i = 0; i < n - 1; i++)
        {
            if ((nums1[i] > back_1 && nums1[i] > back_2) || (nums2[i] > back_1 && nums2[i] > back_2) || (nums1[i] > back_1 && nums2[i] > back_1) || (nums1[i] > back_2 && nums2[i] > back_2))
            {
                valid = false;
                break;
            }
            if (nums1[i] > back_1 && nums1[i] <= back_2 && nums2[i] <= back_1)
            {
                ans++;
            }
            if (nums2[i] > back_2 && nums2[i] <= back_1 && nums1[i] <= back_2)
            {
                ans++;
            }
            // cout << nums1[i] << ' '<<nums2[i]<< ' '<<i << ' ' << ans << endl;
        }
        if (valid)
        {
            res = min(res, ans);
        }
        // cout << res << endl;

        if (res == 1010)
            return -1;
        return res;
    }
};