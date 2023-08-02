//
// Created by 83430 on 2023/7/9.
//
#include <iostream>

using namespace std;

int T, N;

int main(){
    cin >> T;
    for(int t = 1; t <= T; t ++){
        cin >> N;
        int C[N][N];
        for (int i = 0; i < N; i ++){
            for (int j = 0; j < N; j ++){
                cin >> C[i][j];
            }
        }

        int res = 0;
        for(int n = 0; n < N; n ++){
            int cum = 0;
            int i = 0, j = n;
            while(i < N and j < N){
                cum += C[i][j];
                i ++;
                j ++;
            }
            res = max(res, cum);
        }

        for(int n = 1; n < N; n++){
            int cum = 0;
            int i = n, j = 0;
            while(i < N and j < N){
                cum += C[i][j];
                i ++;
                j ++;
            }
            res = max(res, cum);
        }
        printf("Case #%d: %d\n", t, res);
    }
    return 0;
}