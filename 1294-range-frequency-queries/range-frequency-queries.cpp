class RangeFreqQuery {
    unordered_map<int, vector<int>> nums;
public:
// O(N)
    RangeFreqQuery(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++) {
            nums[arr[i]].push_back(i);
        }
    }
    
    // O(log(n))
    int query(int left, int right, int value) {
        vector<int>& indices = nums[value];
        int l = lower_bound(begin(indices), end(indices), left) - begin(indices);
        int r = upper_bound(begin(indices), end(indices), right) - begin(indices);
        return r - l;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */