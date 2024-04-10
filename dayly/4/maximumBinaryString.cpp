class Solution
{
public:
    string maximumBinaryString(string binary)
    {
        // 010 遇到0则想高位变1， 后推1
        int zeroCount = 0;
        int n = binary.size();
        for (auto ch : binary)
        {
            if (ch == '0')
            {
                zeroCount++;
            }
        }
        if (zeroCount == 0)
        {
            return binary;
        }
        // 找到单独0以及0的个数
        // 找到第一个0 开始排偶数个0
        int idx = 0;
        // string ans = "";
        while (idx < n && binary[idx] == '1')
        {
            // ans = ans +  '1';
            idx++;
        }
        // cout << ans << endl;
        // 可以替换则换成0000 -> 1110
        binary.erase(idx, zeroCount);
        if (zeroCount > 1)
        {
            string insertStr(zeroCount - 1, '1');
            binary.insert(idx, insertStr);
            idx += zeroCount - 1;
        }
        binary.insert(idx, "0");
        idx++;
        string insertStr = string(n - idx, '1');
        binary.erase(idx, n - idx);
        binary.insert(idx, insertStr);
        return binary;
        // if (zeroCount > 0)
        // {
        //     while (zeroCount > 1)
        //     {
        //         // ans += "1";
        //         // binary.erase(idx, 1);
        //         binary.insert(idx, "1");
        //         idx++;
        //         zeroCount--;
        //     }
        //     // ans += "0";
        //     binary.insert
        //     idx ++;
        //     zeroCount --;
        // }
        // while(idx < n){
        //     ans += "1";
        //     idx ++;
        // }
        // return ans;
    }
};