#include <iostream>
using namespace std;
int main() {
    int a, b, n;
    while (cin >> n) {
        for (int i = 0; i < n; i ++){
        cin >> a >> b;
        cout << a + b << endl;
        }
    }
    return 0
}