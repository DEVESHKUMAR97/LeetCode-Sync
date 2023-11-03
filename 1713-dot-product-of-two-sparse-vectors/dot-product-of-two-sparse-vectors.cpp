class SparseVector {
    unordered_map<int, int> currVec;
    int dotProduct_(unordered_map<int, int>& smallSparseVector, unordered_map<int, int>& bigSparseVector) {
        int ans = 0;
        for(auto& e: smallSparseVector) {
            if(bigSparseVector.count(e.first)) {
                ans += e.second * bigSparseVector[e.first];
            }
        }
        return ans;
    }
public:
    
    SparseVector(vector<int> &nums) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                currVec[i] = nums[i];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        if(currVec.size() < vec.currVec.size()) {
            return dotProduct_(currVec, vec.currVec);
        }
        return dotProduct_(vec.currVec, currVec);
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);