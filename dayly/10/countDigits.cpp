class Solution {
public:
    int countDigits(int num) {
        int ans = 0;
        int cmt = num;

        while(cmt)
        {
            int t = cmt % 10;
            if (num % t == 0)
            {
                ans ++;
            }
            cmt /= 10;
        }

        return ans;
    }
};