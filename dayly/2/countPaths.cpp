#include <vector>
class Solution
{
public:
    long long countPaths(int n, vector<vector<int>> &edges)
    {
        // 筛质数
        static const int MX = 1e5;
        bool st[MX + 1]{false};
        st[1] = true;
        // 埃氏筛质数
        // 从 2 遍历到 √MX
        for (int i = 2; i * i <= MX; i++)
        {
            if (!st[i])
            {
                // 将 i 的倍数全部标记为 合数
                for (int j = i * i; j <= MX; j += i)
                {
                    st[j] = true;
                }
            }
        }

        // 构建树
        vector<vector<int>> g(n + 1);
        for (auto &e : edges)
        {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        // size 记录每个节点所处连接块的合数节点数
        vector<int> size(n + 1);
        vector<int> nodes;

        // 深度有限遍历 递归函数 记录相连的所有合数节点
        function<void(int, int)> dfs = [&](int x, int fa)
        {
            nodes.push_back(x);
            for (int y : g[x])
            {
                if (y != fa && st[y])
                {
                    dfs(y, x);
                }
            }
        };

        // 题解
        long long ans = 0;

        for (int x = 1; x <= n; x++)
        {
            // 合数跳过
            if (st[x])
                continue;

            // sum 与该节点相连的合数节点数
            int sum = 0;

            // 遍历质数节点的所有连接点
            for (int y : g[x])
            {
                // 质数跳过
                if (!st[y])
                    continue;

                if (size[y] == 0)
                {
                    nodes.clear();
                    dfs(y, -1);
                    for (int z : nodes)
                    {
                        size[z] = nodes.size();
                    }
                }

                ans += (long long)size[y] * sum;
                sum += size[y];
            }
            // 以该节点为终点的路径
            ans += sum;
        }
        return ans;
        /*
        Y总筛质数

        bool st[MX + 1];
        // 需要额外数组包含登记的质数
        int primes[MX], cnt;
        st[1] = true;

        for(int i = 2; i <= MX; i++){
            if(!st[i]){
                prime[cnt ++] = i;
            }
            // 遍历登记的质数
            for(int j = 0; prime[j] <= MX / i; j++){
                // 质数与i的乘积为合数
                st[prime[j] * i] = true;
                if(i % prime[j] == 0){
                    break;
                }
            }
        }
        */
    }
};