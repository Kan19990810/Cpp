"单调栈 ：求每个数左边第一个比它小的数"

#include <bit/stdc++.h>

using namespace std;
const int N = 4e5 + 10;
long long p[N], pp[N], r[N]

int main(){
    int T; cin >> T;

    for (int t = 1; t <= T; t ++){
        int n; cin >> n;
        for (int i = 1; i <= n; i ++){
            int x; scanf("%d", &x);
            p[i] = p[i - 1] + x;
            pp[i] = pp[i - 1] + p[i];
        }
    }
}