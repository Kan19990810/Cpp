class Solution {
public:
    int splitNum(int num) {
        string stnum = to_string(num);

        sort(stnum.begin(), stnum.end());

        int num1 = 0, num2 = 0;

        for(int i = 0; i < stnum.size(); i ++)
        {
            if (i % 2 == 0)
                num1 = num1 * 10 + (stnum[i] - '0');
            else
                num2 = num2 * 10 + (stnum[i] - '0');
        }

        return num1 + num2;
        
        // vector<int> s;

        // while (num)
        // {
        //     int a = num % 10;
        //     s.push_back(a);
        //     num /= 10;
        // }
        // int n = s.size();
        // sort(s.begin(), s.end());

        // int a = 0, b = 0;

        // for (int i = 0; i < n / 2; i ++)
        // {
        //     a *= 10;
        //     a += s[i * 2];
        //     b *= 10;
        //     b += s[i * 2 + 1];
        // }

        // if (n % 2 == 1)
        // {
        //     a *= 10;
        //     a += s[n - 1];
        // }

        // int res = a + b;

        // return res; 
    }
};