#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class UnionFind
{
public:
    UnionFind(int n) : parent(n), val(n)
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            val[i] = 1;
        }
    };

    int find(int x)
    {
        if (parent[x] != x)
        {
            int t = find(parent[x]);
            val[x] *= val[parent[x]];
            parent[x] = t;
        }
        return parent[x];
    }

    // y / x = num
    void unit(int x, int y, double num)
    {
        int paX = find(x);
        int paY = find(y);
        if (paX != paY)
        {
            parent[paX] = paY;
            val[paX] = val[y] * num / val[x];
        }
    }

    double queryVal(int x)
    {
        return val[x];
    }

private:
    // 假设为 parent / x = val;
    vector<int> parent;
    vector<double> val;
};

class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        int nvars = 0;
        unordered_map<string, int> variables;

        int n = equations.size();
        for (int i = 0; i < n; i++)
        {
            if (variables.count(equations[i][0]) == 0)
            {
                variables[equations[i][0]] = nvars++;
            }
            if (variables.count(equations[i][1]) == 0)
            {
                variables[equations[i][1]] = nvars++;
            }
        }

        UnionFind uni(nvars);

        for (int i = 0; i < n; i++)
        {
            int a = variables[equations[i][0]];
            int b = variables[equations[i][1]];
            uni.unit(b, a, values[i]);
        }

        vector<double> res;
        for (auto query : queries)
        {
            if (variables.count(query[0]) == 0 || variables.count(query[1]) == 0)
            {
                res.push_back(-1.0);
                continue;
            }
            int a = variables[query[0]];
            int b = variables[query[1]];
            // cout << a << " " << b << endl;
            int pa = uni.find(a);
            int pb = uni.find(b);
            if (pa == pb)
            {
                res.push_back(uni.queryVal(b) / uni.queryVal(a));
            }
            else
            {
                res.push_back(-1.0);
            }
        }
        return res;
    }
};