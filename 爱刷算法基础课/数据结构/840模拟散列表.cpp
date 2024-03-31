#include <iostream>
#include <cstring>

using namespace std;

const int N = 100003;
int e[N], ne[N], h[N];
int idx, n, x;
char s;

void insert(int x)
{
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx;
    idx++;
}

bool query(int x)
{
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i])
    {
        if (e[i] == x)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> n;
    memset(h, -1, sizeof(h));
    while (n--)
    {
        cin >> s >> x;
        if (s == 'I')
        {
            insert(x);
        }
        else
        {
            if (query(x))
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