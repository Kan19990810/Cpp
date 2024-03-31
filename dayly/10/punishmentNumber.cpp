class Solution {
public:
    bool is_punish(string &str, int pos, int tot, int target){
        if(pos == str.size())
        {
            return tot == target;
        }
        int sum = 0;
        for (int i = pos; i < str.size(); i++)
        {
            sum = sum * 10 + str[i] - '0';
            if (sum + tot > target){
                break;
            }

            if (is_punish(str, i + 1, sum + tot, target)){
                return true;
            }
        }

        return false;
    }

    int punishmentNumber(int n) {
        int res = 0;
        for(int i = 1; i <= n; i++){
            string str = to_string(i * i);
            if(is_punish(str,0, 0, i)){
                res += i * i;
            }
        }    

        return res;
    }
};