#include <iostream>

using namespace std;

const int N = 100010;

int n, m, k;

int q[N];

int main(){
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) scanf("%d", &q[i]);

    while(m --){
        scanf("%d", &k);

        int l = 0, r = n - 1;
        // 求出左端点 [小于 x] [大于等于 x]
        while (l < r){
            int mid = l + r >> 1;
            if (q[mid] >= k) r = mid;
            else l = mid + 1;
        }

        if (q[l] != k) cout << "-1 -1" << endl;
        else{
            cout << l << " ";
            int l = 0, r = n - 1;
            // 求出右端点 [小于等于 x ][大于 x ]
            while (l < r){
                int mid = l + r + 1 >> 1;
                if (q[mid] <= k) l = mid;
                else r = mid - 1;
            }
            cout << l << endl;
        }
    }
    return 0;
}