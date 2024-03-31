class Solution
{
public:
    int countPoints(string rings)
    {
        vector<vector<int>> color_count(10, vector<int>(3, 0));

        for (int i = 0; i < rings.size() / 2; i++)
        {
            if (rings[2 * i] == 'R')
            {
                color_count[rings[2 * i + 1] - '0'][0] = 1;
            }
            else if (rings[2 * i] == 'G')
            {
                color_count[rings[2 * i + 1] - '0'][1] = 1;
            }
            else
            {
                color_count[rings[2 * i + 1] - '0'][2] = 1;
            }
        }

        int res = 0;
        for (int i = 0; i < 10; i++)
        {
            if (color_count[i][0] == 1 && color_count[i][1] == 1 && color_count[i][2] == 1)
            {
                res++;
            }
        }

        return res;
    }
};