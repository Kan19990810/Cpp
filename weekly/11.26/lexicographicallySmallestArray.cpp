class Solution
{
public:
    vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
    {
        int n = nums.size();

        vector<pair<int, int>> idx(n);
        vector<bool> is_used(n);
        vector<int> res(n);

        for (int i = 0; i < n; i++)
        {
            idx[i].first = nums[i];
            idx[i].second = i;
        }
        sort(idx.begin(), idx.end());
        for (int i = 0; i < n;)
        {
            int t = nums[i] - limit;
            int l = 0, r = n - 1;

            // nums[i] - limit 所在位置
            while (l < r)
            {
                int mid = (l + r) >> 1;
                if (idx[mid].first >= t)
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }

            // nums[i]所在的位置
            int c_l = 0, c_r = n - 1;
            while (c_l < c_r)
            {
                int mid = (c_l + c_r) >> 1;
                if (idx[mid].first >= nums[i])
                {
                    c_r = mid;
                }
                else
                {
                    c_l = mid + 1;
                }
            }

            // 可以交换的位置
            cout << "find" << nums[i] << ' ' << c_r << ' ' << t << ' ' << r << endl;
            while (is_used[l] && l < n)
            {
                l++;
            }
            // 如果可以交换的就是自己，那么该位置确定
            // cout << "valid" << l << endl;
            if (i == idx[l].second)
            {
                i++;
                res[i] = nums[i];
                is_used[l] = true;
            }

            // 如果可以交换其他人，需要继续检查
            else
            {
                swap(nums[i], nums[idx[l].second]);
                swap(idx[c_l].second, idx[l].second);
            }
            // cout << "res" << res[i] << endl;
        }
        return res;
    }
};