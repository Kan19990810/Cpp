#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010;
int a[N], s[N];
int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; t ++)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++){
            scanf("%d", &a[i]);
        }
        memcpy(s, a, sizeof a);
        sort(s + 1, s + 1 + n);
        printf("Case #%d: ", t);
        for(int i = 1; i <= n; i ++)
        {
            int l = 1, r = n;
            while(l < r)
            {
                int mid = (l + r) >> 1;
                if(s[mid] > 2 * a[i]) r = mid;
                else l = mid + 1;
            }
            if(s[r] > 2 * a[i]) r--;
            if(a[i] == s[r]) r--;
            if(r != 0) printf("%d", s[r]);
            else printf("%d", -1);
        }
        printf("\n");
    }
    return 0;
}
