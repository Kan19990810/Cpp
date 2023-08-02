//
// Created by Kan on 2023/7/7.
//
#include <iostream>
#include <string>

using namespace std;

int T, n;
string s;

int main(){
    cin >> T;
    for(int t = 1; t <= T; t ++){
        cin >> n >> s;
        printf("Case #%d : 1", t);

//        int f[n];
//        for(int i = 0; i < n; i++) f[i] = 1;
//
//        for(int i = 0; i < n; i ++) {
//            for (int j = 0; j < i; j++) {
//                if (s[i] > s[j]) f[i] = max(f[i], f[j] + 1);
//            }
//            printf(" %d", f[i]);
//        }
//        printf("\n");
        int cur = 1;
        for(int i = 1;i < n; i++){
            if(s[i] > s[i - 1]){
                cur += 1;
                printf(" %d", cur);
            }
            else{
                cur = 1;
                printf(" %d", cur);
            }
        }
        printf("\n");
    }
    return 0;
}