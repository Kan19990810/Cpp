#include <iostream>
#include <string>
// 字符串查询
using namespace std;

const int N = 100010;
// 每个字符都有idx
int trie[N][26], cnt[N], idx;

char str[N];

void insert(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - '0';
        if (!trie[p][u])
            trie[p][u] = ++idx;
        p = trie[p][u];
    }
    cnt[p]++;
}

int query(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - '0';
        if (!trie[p][u])
            return 0;
        p = trie[p][u];
    }
    return cnt[p];
}

int main()
{
    int n;
    cin >> n;
    char op[2];

    for (int i = 1; i <= n; i++)
    {
        scanf("%s%s", op, str);
        if (op[0] == 'I')
            insert(str);
        else
            printf("%d\n", query(str));
    }
    return 0;
}