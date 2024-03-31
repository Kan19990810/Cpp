#include <bits/stdc++.h>

using namespace std;

bool judge(string s, int i)
{
    while(i < s.length())
        if(s[i++] == 'D')
            return false;
    return true;
}

int main()
{
    int T; cin >> T;
    for(int t=1; t<=T; t++)
    {
        int n, d, c, m;
        cin >> n >> d >> c >> m;
        string s; cin >> s;

        int i;
        for(i=0; i<n; i++)
        {
            if(s[i] == 'D')
            {
                if(d == 0) break;
                else d--, c += m;
            }
            else if(s[i] == 'C')
            {
                if(c == 0) break;
                else c--;
            }
        }
        printf("Case #%d: %s\n", t, judge(s, i) ? "YES" : "NO");
    }
    return 0;
}


