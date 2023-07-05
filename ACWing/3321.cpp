#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
const int N = 1e5 + 5;

struct p{
    int rank, index;
}a[N];

bool cmp(p a, p b){
    return a.rank < b.rank || (a.rank == b.rank && a.index < b.index);
}

int t, n, x;
int main(){
    scanf("%d", &t);
    for(int i = 1; i <= t; i ++){
        scanf("%d%d", &n, &x);
        for (int j = 1; j <= n; j++){
            int m;
            scanf("%d", &m);
            a[j].rank = ceil((double) m / x);
            a[j].index = j;
        }
        sort(a + 1, a + n + 1, cmp);
        printf("Case #%d: ", i);
        for (int j = 1; j <= n; j++){
            printf("%d ", a[j].index);
        }
        printf("\n");
    }
    return 0;
}