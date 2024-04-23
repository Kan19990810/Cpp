class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        // 当前满意的客户
        int n = customers.size();
        int satis = 0;

        if (minutes >= n)
        {
            return accumulate(customers.begin(), customers.end(), 0);
        }

        for (int i = 0; i < n; ++i)
        {
            if (grumpy[i] == 0)
            {
                satis += customers[i];
            }
        }

        // 第 k 分钟开始隐忍， 可以提高的满意度
        int maxAdd = 0;
        int curAdd = 0;
        for (int i = 0; i < n - minutes + 1; i++)
        {
            // 初始条件
            if (i == 0)
            {
                for (int j = 0; j < minutes; ++j)
                {
                    if (grumpy[j] == 1)
                    {
                        curAdd += customers[j];
                    }
                }
                maxAdd = max(maxAdd, curAdd);
            }
            else
            {
                if (grumpy[i - 1] == 1)
                {
                    curAdd -= customers[i - 1];
                }
                if (grumpy[i + minutes - 1] == 1)
                {
                    curAdd += customers[i + minutes - 1];
                }
                maxAdd = max(maxAdd, curAdd);
            }
            // cout << i << ' ' << curAdd << ' ' << maxAdd << endl;
        }
        return satis + maxAdd;
    }
};