#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// r 记录余数， 返回商
vector<int> div(vector<int> &A, int b, int &r)
{
    vector<int> C;

    // 从最大位数开始遍历
    for (int i = A.size() - 1; i >= 0; i--)
    {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());

    while (C.size() > 1 && C.back() == 0)
        C.pop_back();

    return C;
}

int main()
{
    string a;
    int b;

    cin >> a >> b;

    vector<int> A;

    // 最小位数在A[0]
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');

    int r = 0;
    vector<int> C = div(A, b, r);

    for (int i = C.size() - 1; i >= 0; i--)
        printf("%d", C[i]);

    cout << endl
         << r;

    return 0;
}