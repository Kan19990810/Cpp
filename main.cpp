#include <bits/stdc++.h>
using namespace std;

void kmp(string a, string b)
{
    int n = a.size();
    int m = b.size();
    vector<int> ne(n + 1);

    for (int i = 2, j = 0; i <= n; ++i)
    {
        while (j && a[i - 1] != a[j])
            j = ne[j];
        if (a[i - 1] == a[j])
            j++;
        ne[i] = j;
    }

    for (int i = 1, j = 0; i <= m; ++i)
    {
        while (j && b[i - 1] != a[j])
            j = ne[j];
        if (b[i - 1] == a[j])
            j++;
        if (j == n)
        {
            cout << i - n << ' ';
        }
    }
}

int main()
{
    string s1 = "aba";
    string s2 = "ababa";
    kmp(s1, s2);
    return 0;
}
