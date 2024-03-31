#include <iostream>
#include <string>
using namespace std;

const int N = 100010;

int l[N], r[N], n[N];
int idx;

void init()
{
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}

void insert_head(int x)
{
    n[idx] = x;
    l[idx] = 0;
    r[idx] = r[0];
    l[r[0]] = idx;
    r[0] = idx;
    idx++;
}

void insert_tail(int x)
{
    n[idx] = x;
    r[idx] = 1;
    l[idx] = l[1];
    r[l[1]] = idx;
    l[1] = idx;
    idx++;
}

void del(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

void insert_left(int k, int x)
{
    n[idx] = x;
    l[idx] = l[k];
    r[idx] = k;
    r[l[k]] = idx;
    l[k] = idx;
    idx++;
}

void insert_right(int k, int x)
{
    n[idx] = x;
    l[idx] = k;
    r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx;
    idx++;
}

int main()
{
    init();
    int m;
    cin >> m;
    while (m--)
    {
        string s;
        cin >> s;
        if (s[0] == 'L')
        {
            int x;
            cin >> x;
            insert_head(x);
        }
        else if (s[0] == 'R')
        {
            int x;
            cin >> x;
            insert_tail(x);
        }
        else if (s[0] == 'D')
        {
            int k;
            cin >> k;
            del(k + 1);
        }
        else if (s[0] == 'I' && s[1] == 'L')
        {
            int k, x;
            cin >> k >> x;
            insert_left(k + 1, x);
        }
        else
        {
            int k, x;
            cin >> k >> x;
            insert_right(k + 1, x);
        }
    }

    for (int i = r[0]; i != 1; i = r[i])
    {
        cout << n[i] << ' ';
    }
    return 0;
}