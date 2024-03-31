#include <iostream>
#include <string>

using namespace std;

const int N = 100010;

int l[N], r[N], e[N];
int idx;

void init()
{
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}

void add_l(int x)
{
    e[idx] = x;
    r[idx] = r[0];
    l[idx] = 0;
    l[r[0]] = idx;
    r[0] = idx;
    idx ++;
}

void add_r(int x)
{
    e[idx] = x;
    r[idx] = 1;
    l[idx] = l[1];
    r[l[1]] = idx;
    l[1] = idx;
    idx ++;
}

void delet(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

void add(int k, int x)
{
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx;
    idx ++;
}



int main()
{
    init();

    int m;
    cin >> m;

    for(int i = 1; i <= m; i ++) 
    {
        string s;
        cin >> s;
        if (s == "L")
        {
            int x;
            cin >> x;
            add_l(x);
        }

        if (s == "R")
        {
            int x;
            cin >> x;
            add_r(x);
        }

        if (s == "D")
        {
            int k;
            cin >> k;
            delet(k + 1);
        }

        if (s == "IR")
        {
            int k, x;
            cin >> k >> x;
            add(k + 1, x);
        }

        if (s == "IL")
        {
            int k, x;
            cin >> k >> x;
            add(l[k + 1], x);
        }

    }

    for(int i = r[0]; i != 1; i = r[i])
    {
        printf("%d ", e[i]);
    }

    // printf("%d", e[l[1]]);
    return 0;
}