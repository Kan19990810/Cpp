#include <iostream>
#include <algorithm>

using namespace std;

// 辗转相除法
int gcb(int a, int b)
{
    return b ? gcb(b, a % b) : a;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        cout << gcb(a, b) << endl;
    }

    return 0;
}