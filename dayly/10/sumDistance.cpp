class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        typedef long long LL;
        
        int n = nums.size();
        int mod = 1e9 + 7;

        vector<LL> pos(n);

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'R')    pos[i] = nums[i] + d;
            else    pos[i] = nums[i] - d;
        }

        sort(pos.begin(), pos.end());

        int res = 0;

        for (int i = 0; i < n - 1; i++) 
        {
            res += (LL) (pos[i + 1] - pos[i]) * (i + 1) % mod * (n - 1 - i) % mod;
            res %= mod;
        }
        return res;
    }
};