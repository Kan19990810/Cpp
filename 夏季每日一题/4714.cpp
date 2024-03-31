//
// Created by 83430 on 2023/7/3.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int F[N];

void init(){
    for(int i=1; i<100010; i++)
    {
        F[i]=i;
        for(int j=2; j<=i/j; j++)
            F[i] = min(F[i], F[i/j]+4+(j-1)*2+i%(i/j));
    }
}

int main(){
    init();
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        int a;
        cin >> a;
        printf("Case #%d: %d\n", i, F[a]);
    }
    return 0;
}