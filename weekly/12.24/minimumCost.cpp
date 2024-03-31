class Solution
{
public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        const static int INF = 1e9;
        int g[26][26];

        for (int i = 0; i < 26; ++i)
        {
            for (int j = 0; j < 26; ++j)
            {
                if (i == j)
                {
                    g[i][j] = 0;
                }
                else
                {
                    g[i][j] = INF;
                }
            }
        }

        for (int i = 0; i < original.size(); ++i)
        {
            g[original[i] - 'a'][changed[i] - 'a'] = min(g[original[i] - 'a'][changed[i] - 'a'], cost[i]);
        }

        for (int t = 0; t < 26; t++)
        {
            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    g[i][j] = min(g[i][j], g[i][t] + g[t][j]);
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < source.size(); ++i)
        {
            if (g[source[i] - 'a'][target[i] - 'a'] == INF)
            {
                return -1;
            }
            else
            {
                ans += g[source[i] - 'a'][target[i] - 'a'];
            }
        }
        return ans;
    }
};