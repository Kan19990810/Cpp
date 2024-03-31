class Solution
{
public:
    int maximizeSquareArea(int m, int n, vector<int> &hFences, vector<int> &vFences)
    {
        // 顶点构成一个正方形
        const static int MOD = 1e9 + 7;
        // 记录所有可能的间隔
        hFences.push_back(1);
        hFences.push_back(m);

        sort(hFences.begin(), hFences.end(), [](int a, int b)
             { return a > b; });

        vector<int> inter_h;
        for (auto hFence_1 = hFences.begin(); hFence_1 < hFences.end(); ++hFence_1)
        {

            for (auto hFence_2 = hFence_1; hFence_2 < hFences.end(); ++hFence_2)
            {
                inter_h.push_back(*hFence_1 - *hFence_2);
            }
        }

        sort(inter_h.begin(), inter_h.end(), [](int a, int b)
             { return a > b; });

        vFences.push_back(1);
        vFences.push_back(n);
        sort(vFences.begin(), vFences.end(), [](int a, int b)
             { return a > b; });

        unordered_set<int> inter_v;
        for (auto vFence_1 = vFences.begin(); vFence_1 < vFences.end(); ++vFence_1)
        {
            for (auto vFence_2 = vFence_1; vFence_2 < vFences.end(); ++vFence_2)
            {
                inter_v.emplace(*vFence_1 - *vFence_2);
            }
        }

        int pre = -1;
        for (auto &h : inter_h)
        {
            if (h == pre)
            {
                continue;
            }
            // cout << h << ' ';
            pre = h;
            if (h != 0 && inter_v.find(h) != inter_v.end())
            {
                return (long long)h * h % MOD;
            }
        }

        return -1;
    }
};