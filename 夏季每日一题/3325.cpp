//
// Created by Kan on 2023/7/7.
//
#include <iostream>
#include <string>

using namespace std;
const int N = 10e5 + 5;
int T;
string s;

int main(){
    cin >> T;
    for (int t = 1; t <= T; t ++){
        cin >> s;
        int res = 0, kick = 0;
        for (int i = 0; i < s.size() - 4; i ++){
            if(s.substr(i, 4) == "KICK") kick ++, i+= 2;
            else if (s.substr(i, 5) == "START") res += kick, i+= 4;
        }
        printf("Case #%d: %d\n", t, res);
    }
    return 0;
}
