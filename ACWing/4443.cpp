 //
// Created by 83430 on 2023/7/6.
//
#include <iostream>
#include <cmath>

using namespace std;
const double pi = 3.141592653;

int T, R, A, B;

int main(){
    cin >> T;
    for(int t = 1; t <= T; t ++){
        cin >> R >> A >> B;
        double res = 0;
        res += pow(R, 2);
        while (R > 0){
            R *= A;
            res += pow(R, 2);
            R = floor(R / B);
            res += pow(R, 2);
        }
        res *= pi;
        printf("Case #%d: %f\n", t, res);
    }
    return 0;
}