class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](const int& a, const int& b) {
            int aSetBits = __builtin_popcount(a);
            int bSetBits = __builtin_popcount(b);
            if(aSetBits != bSetBits) return aSetBits < bSetBits;
            return a < b;
        });
        return arr;
        
    }
};