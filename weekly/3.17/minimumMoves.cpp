#include <vector>
using namespace std;
class Solution
{
    struct dpNode
    {
        long long oneNum;
        // 表示全部移动到左右端点的消费
        long long leftCount;
        long long rightCount;
    };

public:
    long long minimumMoves(vector<int> &nums, int k, int maxChanges)
    {
        int n = nums.size();
        vector<vector<dpNode>> dp(n, vector<dpNode>(n + 2, {0, 0, 0}));

        // 遍历出所有区间,先遍历长度，后遍历起始端点
        for (int st = 0; st < n; st++)
        {
            if (nums[st] == 1)
            {
                dp[st][st].oneNum = 1;
            }
        }

        for (int l = 2; l <= n; l++)
        {
            for (int st = 0; st + l - 1 < n; st++)
            {
                int ed = st + l - 1;
                if (nums[st] == 1)
                {
                    dp[st][ed].oneNum = dp[st + 1][ed].oneNum + 1;
                }
                dp[st][ed].leftCount = dp[st + 1][ed].leftCount + dp[st + 1][ed].oneNum;
                dp[st][ed].rightCount = dp[st][ed - 1].rightCount + dp[st][ed - 1].oneNum;
            }
        }

        long long ans = LONG_LONG_MAX;
        for (int i = 0; i < n; i++)
        {
            bool isOne = false;
            int target = k;
            long long res = 0;

            // 当前位置
            target -= nums[i];
            if (target <= 0)
            {
                ans = min(ans, res);
                continue;
            }

            // 相邻1个位置
            if (i - 1 >= 0 && nums[i - 1])
            {
                target -= nums[i - 1];
                res++;
                if (target <= 0)
                {
                    ans = min(res, ans);
                    continue;
                }
            }
            if (i + 1 < n && nums[i - 1])
            {
                target -= nums[i + 1];
                res++;
                if (target <= 0)
                {
                    ans = min(res, ans);
                    continue;
                }
            }

            // 相邻2个位置
            if (i - 2 >= 0 && nums[i - 2])
            {
                target -= nums[i - 1];
                res += 2;
                if (target <= 0)
                {
                    ans = min(res, ans);
                    continue;
                }
            }

            if (i + 2 < n && nums[i + 2])
            {
                target -= nums[i + 2];
                res += 2;
                if (target <= 0)
                {
                    ans = min(res, ans);
                    continue;
                }
            }

            // 使用maxChange方法
            if (maxChanges >= target)
            {
                res += 2 * target;
                ans = min(ans, res);
                continue;
            }
            target -= maxChanges;

            // 只能继续往左往右查找 双指针查找
            int leftSt = i - 3, leftEd = i - 3;
            int rightSt = i + 3, rightEd = i + 3;
            for (; leftSt >= 0 && rightEd < n; rightEd++)
            {
                if (dp[leftSt][leftEd].oneNum + dp[rightSt][rightEd].oneNum >= target)
                {
                    break;
                }
                while (rightSt >= 0 && dp[leftSt][leftEd].oneNum + dp[rightSt][rightEd].oneNum < target && dp[leftSt][leftEd].rightCount < dp[rightSt][rightEd].leftCount)
                {
                    rightSt--;
                }
                if (dp[leftSt][leftEd].oneNum + dp[rightSt][rightEd].oneNum >= target)
                {
                    break;
                }
            }
            if (dp[leftSt][leftEd].oneNum + dp[rightSt][rightEd].oneNum < target)
            {
                // 当右侧到头
                if (leftSt >= 0)
                {
                    while (dp[leftSt][leftEd].oneNum + dp[rightSt][rightEd].oneNum < target)
                    {
                        leftSt--;
                    }
                }
                // 左侧到头
                if (rightEd < n)
                {
                    while (dp[leftSt][leftEd].oneNum + dp[rightSt][rightEd].oneNum < target)
                    {
                        rightEd--;
                    }
                }
            }
            // 满足条件计算答案；
            res += dp[leftSt][leftEd].rightCount + dp[leftSt][leftEd].oneNum * 3 + dp[rightSt][rightEd].leftCount + dp[rightSt][rightEd].oneNum * 3;
            ans = min(ans, res);
        }
        return ans;
    }
};