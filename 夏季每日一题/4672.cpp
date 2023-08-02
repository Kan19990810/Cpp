//
// Created by 83430 on 2023/7/4.
//
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;
int tt, n, Case;

//q1 按照 cmp1 的方式排序
//q2 按照 cmp2 的方式排序
struct node {
    string c;
    int d, u;
} q1[N], q2[N];

bool cmp1(node a, node b) {
    return a.c < b.c || a.c == b.c && a.u < b.u;
}

bool cmp2(node a, node b) {
    return a.d < b.d || a.d == b.d && a.u < b.u;
}

int main() {
    scanf("%d", &tt);
    while (tt --) {
        scanf("%d", &n);
        for (int i = 0; i < n; i ++) {
            cin >> q1[i].c;
            scanf("%d%d", &q1[i].d, &q1[i].u);
            //要将 q1 的所有数据都 copy 进 q2
            q2[i] = q1[i];
        }
        //分别排好序
        sort(q1, q1 + n, cmp1);
        sort(q2, q2 + n, cmp2);
        int res = 0;
        //判断有几个位置相等并且值也相等
        for (int i = 0; i < n; i ++)
            if (q1[i].c == q2[i].c && q1[i].d == q2[i].d && q1[i].u == q2[i].u)
                res ++;
        printf("Case #%d: %d\n", ++Case, res);
    }
    return 0;
}
