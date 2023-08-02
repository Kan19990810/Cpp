#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
char s[N];
int l[N], r[N], n;

int main () {
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; t ++) {
        scanf("%d%s", &n, s + 1);
        l[0] = -1e6, r[n + 1] = 1e6;

        for (int i = 1; i <= n; i ++)
            l[i] = s[i] == '1' ? i : l[i - 1];

        for (int i = n; i >= 1; i --)
            r[i] = s[i] == '1' ? i : r[i + 1];

        long long ans = 0;
        for (int i = 1; i <= n; i ++)
            ans += min(i - l[i], r[i] - i);

        printf("Case #%d: %lld\n", t, ans);
    }
    return 0;
}
