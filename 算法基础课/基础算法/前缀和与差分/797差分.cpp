// 差分 前缀和的逆运算
// 构造b 差分数组使得 ai = b1 +  ... + bi
// bi = ai - ai-1
#include <iostream>

using namespace std;

const int N = 100010;

int n, m;

int a[N], b[N];

void insert(int l, int r, int c){
    b[l] += c;
    b[r + 1] -= c;
}

int main(){
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);

    for (int i = 1; i <= n; i ++) insert(i, i, a[i]);

    for (int i = 1; i <= m; i ++){
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c);
    }

    for (int i = 1; i <= n; i++) b[i] += b[i - 1];

    for (int i = 1; i <= n; i++) printf("%d ", b[i]);

    return 0;
}
