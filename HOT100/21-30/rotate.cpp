class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // x, y 互换位置 然后对于 y 对称
        int n = matrix.size();
        // 遍历所有需要旋转一周的位置
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < (n + 1) / 2; j++)
            {
                // 记录起始位置和值
                int oriX = i, oriY = j;
                int curNum = matrix[oriX][oriY];
                for (int t = 1; t <= 4; t++)
                {
                    // 找到旋转后的位置和值
                    int nexX = oriY, nexY = oriX;
                    nexY = n - nexY - 1;
                    int tmpNum = matrix[nexX][nexY];
                    matrix[nexX][nexY] = curNum;
                    // 根据旋转后的位置和值开始旋转
                    oriX = nexX;
                    oriY = nexY;
                    curNum = tmpNum;
                }
            }
        }
        return;
    }
};