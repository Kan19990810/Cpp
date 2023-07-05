#include <bits/stdc++.h>

using namespace std;

int main(){
    int T; cin >> T;
    for(int t = 1; t <= T; t ++){
        string s, f;
        cin >> s >> f;
        int ans = 0;
        for(auto src: s)
        {
            int a = src - 'a';
            int m = 26;
            for (auto to : f)
            {
                int b = to - 'a';
                m = min (m, min ((a - b + 26) % 26, (b - a + 26) % 26));
            }
            ans += m;
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}