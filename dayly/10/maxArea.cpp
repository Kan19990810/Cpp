class Solution
{
public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
    {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);

        int max_h = horizontalCuts[0];
        int max_w = verticalCuts[0];

        // for(auto it = horizontalCuts.begin(); it < horizontalCuts.end(); it++){
        //     cout << *it << ' ';
        // }
        // cout << endl;
        // for(auto it = verticalCuts.begin(); it < verticalCuts.end(); it ++){
        //     cout << *it << ' ';
        // }
        // cout << endl;

        const int mod = 1e9 + 7;

        for (int i = 0; i < horizontalCuts.size() - 1; i++)
        {
            max_h = max(max_h, horizontalCuts[i + 1] - horizontalCuts[i]);
            // cout << max_h << ' ';
        }
        // cout << endl;

        for (int i = 0; i < verticalCuts.size() - 1; i++)
        {
            max_w = max(max_w, verticalCuts[i + 1] - verticalCuts[i]);
            // cout << max_w << ' ';
        }
        // cout << endl;

        return (long long)max_h * max_w % mod;
    }
};