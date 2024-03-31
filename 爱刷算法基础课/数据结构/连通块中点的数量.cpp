#include <iostream>
#include <string>
using namespace std;

const int N = 100010;
int n, m, a, b;
string s;
int p[N], cnt[N];

void init()
{
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        cnt[i] = 1;
    }
}

int find(int x)
{
    if (p[x] != x)
    {
        p[x] = find(p[x]);
    }
    return p[x];
}

void connect(int a, int b)
{
    int p_a = find(a);
    int p_b = find(b);
    if (find(a) == find(b))
    {
        return;
    }
    p[p_a] = p_b;
    cnt[p_b] += cnt[p_a];
    return;
}

bool query_1(int a, int b)
{
    return (find(a) == find(b));
}

int query_2(int a)
{
    return cnt[find(a)];
}

int main()
{
    cin >> n >> m;
    init();
    while (m--)
    {
        cin >> s;
        if (s == "C")
        {
            cin >> a >> b;
            connect(a, b);
        }
        else if (s == "Q1")
        {
            cin >> a >> b;
            query_1(a, b) ? cout << "Yes" << endl : cout << "No" << endl;
        }
        else
        {
            cin >> a;
            cout << query_2(a) << endl;
        }
    }
    return 0;
}