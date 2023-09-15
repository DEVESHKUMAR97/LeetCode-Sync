class Solution {
    // [-2*bucketSize, -bucketSize-1] -> -2 id
    // [-bucketSize, -1] -> -1 id
    // [0, bucketSize - 1] -> 0 id
    // [bucketSize, 2*bucketSize - 1] -> 1 id
    // [2*bucketSize, 3*bucketSize - 1] -> 2 id
    // [3*bucketSize, 4*bucketSize - 1] -> 3 id
    int getBucketId(int num, int bucketSize) {
        if(num >= 0) {
            return num / bucketSize;
        }

        return (num+1)/ bucketSize - 1;

    }
public:
    // approach 2: using bucket sort concept, comparing elements with in buckets
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        if(nums.size() == 1) return false;
        int n = nums.size();

        int bucketSize = valueDiff + 1;
        unordered_map<int, int> buckets;

        for(int i = 0; i < n; i++) {
            int id = getBucketId(nums[i], bucketSize);

            if(buckets.count(id)) return true;

            if(buckets.count(id - 1) && abs(nums[i] - buckets[id-1]) < bucketSize)
                return true;

            if(buckets.count(id + 1) && abs(nums[i] - buckets[id+1]) < bucketSize)
                return true;
            
            buckets[id] = nums[i];

            if(i >= indexDiff) {
                buckets.erase(getBucketId(nums[i-indexDiff], bucketSize));
            }
        }

        return false;

    }

    // // approach 1: Intuitive O(n * log(n)) using lower_bound
    // bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
    //     if(nums.size() == 1) return false;
    //     set<int> prevSet;
    //     set<int>::iterator itr;

    //     for(int i = 0; i < nums.size(); i++) {
    //         if(prevSet.size() > 0) {
    //             itr = lower_bound(prevSet.begin(), prevSet.end(), nums[i]);
    //             if(itr != prevSet.end()) {
    //                 if(abs(*itr - nums[i]) <= valueDiff) return true;
    //             }
    //             if(itr != prevSet.begin()) {
    //                 itr--;
    //                 if(abs(*itr - nums[i]) <= valueDiff) return true;
    //             }
    //         }
    //         prevSet.insert(nums[i]);
    //         if(i-indexDiff >= 0) {
    //             prevSet.erase(nums[i-indexDiff]);
    //         }
    //     }
    //     return false;
    // }
};