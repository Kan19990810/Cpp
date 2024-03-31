#include <iostream>
using namespace std;

const int N = 100010;
int p[N];

void init(int x)
{
    for (int i = 1; i <= x; i++)
    {
        p[i] = i;
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

void merge(int a, int b)
{
    p[find(a)] = find(b);
}

bool query(int a, int b)
{
    return (find(a) == find(b));
}

int main()
{
    int n, m;
    cin >> n >> m;
    init(n);
    while (m--)
    {
        char s;
        cin >> s;

        if (s == 'M')
        {
            int a, b;
            cin >> a >> b;
            merge(a, b);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            if (query(a, b))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}