#include <iostream>

using namespace std;

const int N = 100010;

int n[N], ne[N];
int M;
int head, idx;

void init()
{
    head = -1;
    idx = 0;
}

void add_head(int x)
{
    n[idx] = x;
    ne[idx] = head;
    head = idx;
    idx ++;
}

void delet(int k)
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
    // 
    n[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx ++;
}


int main()
{
    init();
    scanf("%d", &M);
    for (int i = 1; i <= M; i ++)
    {
        char s;
        cin >> s;
        if (s == 'H')
        {   
            int x;
            cin >> x;
            add_head(x);
        }

        if (s == 'D')
        {
            int k;
            cin >> k;
            delet(k - 1);
        }

        if (s == 'I')
        {
            int k, x;
            cin >> k >> x;
            insert(k - 1, x);
        }
    } 
    for(int i = head; i != -1; i = ne[i])
    {
        printf("%d ", n[i]);
    }
    return 0;
}