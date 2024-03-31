class Solution
{
public:
    int isWinner(vector<int> &player1, vector<int> &player2)
    {
        int n = player1.size();
        int ans = 0;
        bool is_ten = false;
        int ten_idx = -1;
        for (int i = 0; i < n; ++i)
        {
            if (is_ten)
            {
                ans += player1[i] * 2;
            }
            else
            {
                ans += player1[i];
            }
            if (player1[i] == 10)
            {
                is_ten = true;
                ten_idx = i;
            }
            if (i - ten_idx > 1 && is_ten)
            {
                is_ten = false;
            }
        }

        is_ten = false;
        ten_idx = -1;
        for (int i = 0; i < n; ++i)
        {
            if (is_ten)
            {
                ans -= player2[i] * 2;
            }
            else
            {
                ans -= player2[i];
            }
            if (player2[i] == 10)
            {
                is_ten = true;
                ten_idx = i;
            }
            if (i - ten_idx > 1 && is_ten)
            {
                is_ten = false;
            }
        }

        if (ans == 0)
        {
            return 0;
        }
        else if (ans > 0)
        {
            return 1;
        }
        return 2;
    }
};