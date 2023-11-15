class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int maxx = 1;
        int last = 1;

        sort(arr.begin(), arr.end());


        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] > last) {
                last++;
                maxx = last;
            }
        }
        return maxx;
    }
};