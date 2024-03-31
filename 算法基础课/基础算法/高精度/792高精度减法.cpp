#include <iostream>
#include <vector>

using namespace std;

const int N = 100010;

bool cmp(vector<int> &A, vector<int> &B)
{
    if (A.size() != B.size())
        return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; i--)
    {
        if (A[i] != B[i])
            return A[i] > B[i];
    }
    return true;
}

vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;

    for (int i = 0, t = 0; i < A.size(); i++)
    {
        // t 表示进位
        t = A[i] - t;
        // 处理B[i]
        if (i < B.size())
            t -= B[i];
        // 计算结果
        C.push_back((t + 10) % 10);
        // 处理进位t
        if (t < 0)
            t = 1;
        else
            t = 0;
    }
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();

    return C;
}

int main()
{
    string a, b;
    vector<int> A, B;

    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0');
    // 保持大数减小数
    if (cmp(A, B))
    {
        vector<int> C = sub(A, B);

        for (int i = C.size() - 1; i >= 0; i--)
            printf("%d", C[i]);
    }
    else
    {
        vector C = sub(B, A);

        printf("-");
        for (int i = C.size() - 1; i >= 0; i--)
            printf("%d", C[i]);
    }
    return 0;
}