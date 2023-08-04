// 前面的数比后面的数大
#include <iostream>

using namespace std;

const int N = 100010;

int n;
int q[N], tmp[N];

long long merge_sort(int l, int r){
    if (l >= r) return 0;

    int mid = l + r >> 1;

    long long res = merge_sort(l, mid) + merge_sort(mid + 1, r);

    int k = 0, i = l, j = mid + 1;

    while (i <= mid && j <= r){
        if (q[i] <= q[j]) tmp[k ++] = q[i ++];
        else{
            tmp[k ++] = q[j ++];
            res += mid - i + 1;
        }
    }

    while (i <= mid) tmp[k ++] = q[i ++];
    while (j <= r) tmp[k ++] = q[j ++];

    for (int i = l, j = 0; i <= r; i ++, j ++) q[i] = tmp[j];

    return res;
}

int main(){
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &q[i]);

    printf("%d ", merge_sort(0, n - 1));

    // for (int i = 0; i < n; i++) printf("%d ", q[i]);
    
    return 0;
}