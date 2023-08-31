#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

vector<PII> segs;

int n;
int l, r;

void merge(vector<PII> &segs){
    vector<PII> res;
    
    sort(segs.begin(), segs.end());

    int st = -2e9, ed = -2e9;

    for(auto seg : segs){
        if(ed < seg.first){
            if (ed != -2e9) res.push_back({st, ed});
            st, ed = seg.first, seg.second;
        }
        else{
            ed = max(ed, seg.second);
        }
    }
    if (ed != -2e9){
        res.push_back({st, ed});
    }

    segs = res;
}


int main(){
    scanf("%d", n);

    for (int i = 1; i <= n; i++){
        scanf("%d%d", &l, &r);
        segs.push_back({l, r});
    }

    merge(segs);

    printf("%d", segs.size());

    return 0;
}

