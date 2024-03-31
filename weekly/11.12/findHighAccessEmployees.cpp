#include <string>
class Solution
{
public:
    vector<string> findHighAccessEmployees(vector<vector<string>> &access_times)
    {
        sort(access_times.begin(), access_times.end());
        vector<string> res;

        int count = 0;
        queue<int> time;
        int n = access_times.size();

        for (int i = 0; i < n; i++)
        {
            int hour = (access_times[i][1][0] - '0') * 10 + access_times[i][1][1] - '0';
            int mini = (access_times[i][1][2] - '0') * 10 + access_times[i][1][3] - '0';
            int now = hour * 60 + mini;
            // cout << access_times[i][0] << ' ' << hour << ' ' << mini << ' ' << now << endl;
            if (i == 0)
            {
                // cout << "start" << endl;
                count = 1;
                time.push(now);
                continue;
            }
            if (access_times[i][0] == access_times[i - 1][0])
            {
                if (count == 3)
                {
                    continue;
                }
                int last = time.front();
                while (time.size() && abs(last - now) >= 60)
                {
                    time.pop();
                    last = time.front();
                    count--;
                }
                time.push(now);
                count++;
                if (count == 3)
                {
                    res.push_back(access_times[i][0]);
                }
            }
            else
            {
                // cout << "pass" << endl;
                while (!time.empty())
                {
                    time.pop();
                }
                count = 1;
                time.push(now);
            }
        }
        // cout << endl;
        return res;
    }
};