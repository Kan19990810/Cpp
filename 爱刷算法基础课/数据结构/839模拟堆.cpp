#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int N = 100010;
int d[N], seq[N], pos[N];
int idx, s;
int n, k, x;
string str;

void heap_swap(int k, int t)
{
    swap(seq[pos[k]], seq[pos[t]]);
    swap(pos[k], pos[t]);
    swap(d[k], d[t]);
}

void down(int k)
{
    int t = k;
    if (2 * k <= s && d[t] > d[2 * k])
    {
        t = 2 * k;
    }
    if (2 * k + 1 <= s && d[t] > d[2 * k + 1])
    {
        t = 2 * k + 1;
    }
    if (t != k)
    {
        heap_swap(t, k);
        down(t);
    }
}

void up(int k)
{
    while (k / 2 && d[k] < d[k / 2])
    {
        heap_swap(k, k / 2);
        k /= 2;
    }
}

void insert(int x)
{
    s++;
    idx++;
    d[s] = x;
    seq[idx] = s;
    pos[s] = idx;
    up(s);
}

int heap_min()
{
    return d[1];
}

void del_head()
{
    heap_swap(1, s);
    s--;
    down(1);
}

void del_k(int k)
{
    int t = seq[k];
    heap_swap(t, s);
    s--;
    down(t);
    up(t);
}

void change(int k, int x)
{
    int t = seq[k];
    d[t] = x;
    down(t);
    up(t);
}

int main()
{
    cin >> n;
    while (n--)
    {
        cin >> str;
        if (str == "I")
        {
            cin >> x;
            insert(x);
        }
        else if (str == "PM")
        {
            cout << heap_min() << endl;
        }
        else if (str == "DM")
        {
            del_head();
        }
        else if (str == "D")
        {
            cin >> k;
            del_k(k);
        }
        else
        {
            cin >> k >> x;
            change(k, x);
        }
    }
    return 0;
}
