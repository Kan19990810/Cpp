#include<iostream>

using namespace std;

const int N = 100010;

int trie[N][26], cnt[N], idx;

int n;
char op[2], str[N];

void insert(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!trie[p][u]) trie[p][u] = ++idx;
        p = trie[p][u];
    }
    cnt[p] ++;
}

int query(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!trie[p][u]) return 0;
        p = trie[p][u];
    }
    return cnt[p];
}

int main()
{
    cin >> n;
    while(n --)
    {
        cin >> op >> str;
        if(op[0] == 'I') insert(str);
        else cout << query(str) << endl;
    }

    return 0;
}