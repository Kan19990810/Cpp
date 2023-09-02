#include <iostream>
#include <string>

using namespace std;

const int N = 100010;

int s[N], tt = 0, hh = 0;

int main()
{
    int m;
    cin >> m;
    for (int i = 1; i <= m; i ++)
    {
        string str;
        cin >> str;
        if (str == "push")
        {
            int x;
            cin >> x;
            s[hh ++] = x;
        }
        if (str == "pop")
        {
            tt ++;
        }
        if (str == "empty")
        {
            if(hh > tt) printf("NO\n");
            else printf("YES\n");
        }
        if (str == "query")
        {
            printf("%d\n", s[tt]);
        }
        
    }
    return 0;
}