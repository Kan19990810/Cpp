// 存储结构 开放寻址法  拉链法


// 开放寻址法 一维数组 2 - 3 * N

#include <iostream>
#include <cstring>

using namespace std;

const int N = 200003, null = 0x3f3f3f;

int h[N];

int find( int x)
{
    int k = (x % N + N) % N;

    while (h[k] != null && h[k] != x)
    {
        k ++;
        if (k == N ) k = 0;
    }
    return k;
}


int main()
{
    int n ; 
    scanf("%d", &n);

    memset(h, 0x3f, sizeof(h));

    while (n --)
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);

        int k = find(x)

        if (op[0] == 'I') h[k] = x;

        else 
        {
            if(h[k] != null) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
// 拉链法 一维数组 + 链表
#include <iostream>
#include <cstring>

using namespace std;

const int N = 100003;

int h[N], e[N], ne[N], idx;
int n, x;
char op[2];

void insert(int x)
{
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx ++;
    // cout << x  << ' '<< k << ' ' << h[k] << ' ' << e[h[k]] << endl;
}

bool find(int x)
{
    int k = (x % N + N ) % N;
    // cout <<x <<' ' << k << ' ' << h[k] << ' '<< e[h[k]] << endl;
    for (int i = h[k] ; i != -1; i = ne[i])
    {
        if (e[i] == x) return true; 
    }
    return false;
}

int main()
{
    memset(h, -1, sizeof(h));
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf("%s%d", op, &x);
        if (op[0] == 'I') insert(x);
        else
        {
            if (find(x)) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}