class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        while(i < n) {
            int low = i;
            while(i + 1 < n && arr[i] == arr[i+1]) {
                i++;
            }
            int freq = i - low + 1;
            if(freq * 4 > n) {
                return arr[low];
            }
            i++;
        }
        return -1;
        
    }
};