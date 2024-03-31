class Solution
{
private:
    int dfs(int n)
    {
        if (n == 0 || n == 1)
        {
            return 1;
        }
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            res = res + dfs(i - 1) * dfs(n - i);
        }
        return res;
    }

public:
    int numTrees(int n)
    {
        return dfs(n);
    }
};