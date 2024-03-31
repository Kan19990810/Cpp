#include <iostream>
#include <vector>

using namespace std;

// A为特别大数使用数组表示， B为正常数字
vector<int> mul(vector<int> &A, int B)
{
    vector<int> C;

    int t = 0;
    for (int i = 0; i < A.size() | t; i++)
    {
        // 各个位数依次相乘
        if (i < A.size())
            t += A[i] * B;
        C.push_back(t % 10);
        t /= 10;
    }

    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}

int main()
{
    string a;
    int B;
    vector<int> A;

    cin >> a >> B;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');

    vector<int> C = mul(A, B);

    for (int i = C.size() - 1; i >= 0; i--)
        printf("%d", C[i]);

    return 0;
}