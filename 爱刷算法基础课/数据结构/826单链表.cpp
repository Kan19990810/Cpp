// idx 从 0 开始， k 从 1 开始
#include <iostream>
using namespace std;

const int N = 100010;
int n[N], ne[N];
int idx, head;

void init()
{
    head = -1;
    idx = 0;
}

void insert_head(int x)
{
    n[idx] = x;
    ne[idx] = head;
    head = x;
    idx++;
}

void del(int k)
{
    if (k < 0)
    {
        head = ne[head];
    }
    else
    {
        ne[k] = ne[ne[k]];
    }
}

void insert(int k, int x)
{
    n[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

int main()
{
    init();
    int m;
    cin >> m;
    while (m--)
    {
        char s;
        cin >> s;
        if (s == 'H')
        {
            int x;
            cin >> x;
            insert_head(x);
        }
        else if (s == 'D')
        {
            int k;
            cin >> k;
            del(k - 1);
        }
        else
        {
            int k, x;
            cin >> k >> x;
            insert(k - 1, x);
        }
    }

    for (int i = head; i != -1; i = ne[i])
    {
        cout << n[i] << ' ';
    }
    return 0;
}
