#include <iostream>

using namespace std;

const int N = 1000010;

int n, m;
char p[N], s[N];
int ne[N];

// KMP 字符串匹配
int main()
{
    cin >> n >> p + 1 >> m >> s + 1;
    for (int i = 2, j = 0; i <= n; i++)
    {
        // j  比较的前一个位置 , 比较使用j + 1
        while (j && p[i] != p[j + 1])
            j = ne[j];
        if (p[i] == p[j + 1])
            j++;
        ne[i] = j;
    }

    for (int i = 1, j = 0; i <= m; i++)
    {
        while (j && s[i] != p[j + 1])
            j = ne[j];
        if (s[i] == p[j + 1])
            j++;
        if (j == n)
        {
            printf("%d ", i - n);
        }
    }
    return 0;
}