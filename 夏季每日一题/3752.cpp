//
// Created by 83430 on 2023/7/6.
//
#include <iostream>
#include <string>

using namespace std;
const long long mod = 1e9 + 7;

int T, N, K;
string S;

long long modPow(int x, int e){
    if (e == 0) return 1;
    long long a = modPow(x, e >> 1);
    a = a * a % mod;
    if (e & 1) a = a * x % mod;
    return a;
}

int main(){
    cin >> T;
    for(int t = 1; t <= T; t ++){
        cin >> N >> K >> S;
        long long ans = 0;
        int mid = (N - 1) /2;
        for ( int i = 0; i <= mid; i++) {
            ans += (S[i] - 'a') * modPow(K, mid - i);
        }
        for ( int i = (N + 1) / 2; i < N; i ++){
            int j = N - i - 1;
            if (S[j] == S[i]) continue;
            if (S[j] < S[i]) ans ++;
            break;
        }
        printf("Case #%d: %lld\n", t, ans % mod);
    }
    return 0;
}
