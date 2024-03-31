#include <vector>
#include <set>
#include <algorithm>
class Solution
{
public:
    vector<int> resultArray(vector<int> &nums)
    {
        int n = nums.size();
        // arr1, arr2数组
        vector<int> arr1;
        vector<int> arr2;
        // 维护arr中大于任何数的数组
        // 如何快速执行greaterCount(arr, val)
        multiset<int> arr_set1;
        multiset<int> arr_set2;

        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                arr1.push_back(nums[i]);
                arr_set1.emplace(nums[i]);
                // cout << 1 << ' ' << nums[i] << endl;
                continue;
            }
            if (i == 1)
            {
                arr2.push_back(nums[i]);
                arr_set2.emplace(nums[i]);
                // cout << 2 << ' ' << nums[i] << endl;
                continue;
            }
            auto cnt1 = distance(arr_set1.upper_bound(nums[i]), arr_set1.end());
            auto cnt2 = distance(arr_set2.upper_bound(nums[i]), arr_set2.end());
            // cout << "cnt1:" << cnt1 << "cnt2:" << cnt2 << endl;
            if (cnt1 > cnt2)
            {
                arr1.push_back(nums[i]);
                arr_set1.emplace(nums[i]);
                // cout << 1 << ' ' << nums[i] << endl;
            }
            else if (cnt1 < cnt2)
            {
                arr2.push_back(nums[i]);
                arr_set2.emplace(nums[i]);
                // cout << 2 << ' ' << nums[i] << endl;
            }
            else
            {
                int s1 = arr1.size();
                int s2 = arr2.size();
                if (s1 <= s2)
                {
                    arr1.push_back(nums[i]);
                    arr_set1.emplace(nums[i]);
                    // cout << 1 << ' ' << nums[i] << endl;
                }
                else
                {
                    arr2.push_back(nums[i]);
                    arr_set2.emplace(nums[i]);
                    // cout << 2 << ' ' << nums[i] << endl;
                }
            }
        }

        int n1 = arr1.size();
        int n2 = arr2.size();
        arr1.resize(n1 + n2);
        copy(arr2.begin(), arr2.end(), arr1.begin() + n1);
        // for (auto &num : arr2)
        // {
        //     arr1.push_back(num);
        // }
        return arr1;
    }
};