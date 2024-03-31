class Solution {
public:
    bool is_valid(int x, vector<int>& citations){
        int n = citations.size();
        
        return citations[n - x] >= x;
    }

    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n;
        while (left < right){
            int mid = (left + right + 1) >> 1;
            if(is_valid(mid, citations)){
                left = mid;
            }
            else{
                right = mid - 1;
            }
        }
        return left;
    }
};