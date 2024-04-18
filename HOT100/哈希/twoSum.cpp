#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<pair<int, int>> numPair;
        for (int i = 0; i < n; i++)
        {
            numPair.push_back({nums[i], i});
        }
        sort(numPair.begin(), numPair.end());
        for (int i = 0, j = n - 1; i < j; j--)
        {
            while (numPair[i].first + numPair[j].first < target)
            {
                i++;
            }
            if (numPair[i].first + numPair[j].first == target)
            {
                return {numPair[i].second, numPair[j].second};
            }
        }
        return {-1, -1};
    }
};