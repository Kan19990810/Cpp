// "单调栈 ：求每个数左边第一个比它小的数"

#include <bits/stdc++.h>

using namespace std;
const int N = 4e5 + 10;
long long p[N], pp[N], r[N];

int main(){
    int T; cin >> T;

    for (int t = 1; t <= T; t ++){
        int n; cin >> n;
        for (int i = 1; i <= n; i ++){
            int x; scanf("%d", &x);
            p[i] = p[i - 1] + x;
            pp[i] = pp[i - 1] + p[i];
        }


        stack<int> stk;
        stk.push(n + 1), p[n + 1] = -1e9;
        for (int i = n; i >= 0; i --){
            while(p[i] <= p[stk.top()]) {
                stk.pop();
            }
            r[i + 1] = stk.top() - 1;
            stk.push(i);
        }

        long long res = 0;
        for (int i = 1; i <= n; i ++)
        {
            int j = r[i];
            res += pp[j] - pp[i - 1] - (j - i + 1) * p[i - 1];
        }
        printf("Case #%d: %d\n", t, res);
    }
    return 0;
}