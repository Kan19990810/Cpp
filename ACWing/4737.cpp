#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10;

int t, rs, rh, n, m;
double da[N], db[N];

int main() {
    cin >> t;

    int x, y, r;
    for (int k = 1; k <= t; k ++ ) {
        cin >> rs >> rh;
        r = da[0] = db[0] = (rs + rh) * (rs + rh);

        cin >> n;
        for (int i = 0; i < n; i ++ ) cin >> x >> y, da[i] = x * x + y * y;
        cin >> m;
        for (int i = 0; i < m; i ++ ) cin >> x >> y, db[i] = x * x + y * y;
        sort(da, da + n), sort(db, db + m);

        int a = 0, b = 0;
        while (a < n && da[a] <= db[0] && da[a] <= r) a ++ ;
        while (b < m && db[b] <= da[0] && db[b] <= r) b ++ ;

        cout << "Case #" << k << ": " << a << ' ' << b << endl;
    }

    return 0;
}
