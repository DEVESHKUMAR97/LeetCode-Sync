class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int idx1 = min_element(begin(nums), end(nums)) - begin(nums);
        int idx2 = max_element(begin(nums), end(nums)) - begin(nums);
        if(idx1 > idx2) swap(idx1, idx2);


        // now idx1 is always smaller 
        int n = nums.size();

        function<int(int,int)> deleteFromStart = [](int idx, int n) {
            return idx + 1;
        };

        function<int(int,int)> deleteFromEnd = [](int idx, int n) {
            return n - idx;
        };


        int ans1 = deleteFromStart(idx1, n) + deleteFromEnd(idx2, n);
        int ans2 = deleteFromStart(idx2, n);
        int ans3 = deleteFromEnd(idx1, n);
        return min(ans1, min(ans2, ans3));
        
    }
};