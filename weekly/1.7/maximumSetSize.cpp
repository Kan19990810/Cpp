class Solution
{
public:
    int maximumSetSize(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        unordered_set<int> numsSet1, numsSet2, numsSet;
        for (auto &num : nums1)
        {
            numsSet1.emplace(num);
            numsSet.emplace(num);
        }
        for (auto &num : nums2)
        {
            numsSet2.emplace(num);
            numsSet.emplace(num);
        }
        int m1 = numsSet1.size();
        int m2 = numsSet2.size();
        int m3 = numsSet.size();
        // cout << n / 2 << ' ' << m1 << ' ' << m2 << ' ' << m3 << endl;

        if (m1 <= n / 2 && m2 <= n / 2)
        {
            return m3;
        }
        else if (m1 > n / 2 && m2 <= n / 2)
        {
            int tmp1 = m1 + m2 - m3;
            int tmp2 = m1 - n / 2;
            if (tmp1 >= tmp2)
            {
                return m3;
            }
            else
            {
                return m3 - (tmp2 - tmp1);
            }
        }
        else if (m2 > n / 2 && m1 <= n / 2)
        {
            int tmp1 = m1 + m2 - m3;
            int tmp2 = m2 - n / 2;
            return m3 - max(0, tmp2 - tmp1);
        }
        else
        {
            int tmp1 = m1 + m2 - m3;
            int tmp2 = m1 - n / 2 + m2 - n / 2;
            if (tmp1 >= tmp2)
            {
                return m3;
            }
            else
            {
                return m3 - (tmp2 - tmp1);
            }
        }
    }
};