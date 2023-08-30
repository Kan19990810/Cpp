#include <iostream>
#include <string>

using namespace std;

const int N = 100010;
int m;
int s[N], tt = 0;


int main()
{
    scanf("%d", &m);

    for(int i = 0; i< m; i++)
    {
        string str;
        cin >> str;
        if(str == "push")
        {
            int x;
            cin >> x;
            s[tt ++] = x;
        }

        if (str == "pop")
        {
            tt --;
        }

        if (str == "empty")
        {
            if (tt == 0) printf("YES\n");
            else printf("NO\n");
        }

        if (str == "query")
        {
            printf("%d\n", s[tt - 1]);
        }
        // printf("%d ", tt);
    }
    return 0;
}