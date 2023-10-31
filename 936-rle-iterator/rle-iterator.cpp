#define ll long long
class RLEIterator {
    vector<ll> prefixCount;
    vector<ll> nums;
    ll targetNumPosition;
    ll currNumLeftIdx;
public:
    // Approach 2: Using binary search
    // O(n) for constructor
    RLEIterator(vector<int>& encoding) {
        targetNumPosition = 0;
        currNumLeftIdx = 0;
        for(int i = 0; i < encoding.size(); i += 2) {
            if(encoding[i] != 0) {
                if(prefixCount.size() == 0) {
                    prefixCount.push_back(encoding[i]);
                } else {
                    prefixCount.push_back(encoding[i] + prefixCount.back()); 
                }
                nums.push_back(encoding[i+1]);
            }
        }
    }
    

    // O(log(n)) for next call and O(1) amortized
    int next(int n) {
        targetNumPosition += n;
        int low = currNumLeftIdx;
        int high = nums.size() - 1;
        int ansIdx = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(prefixCount[mid] >= targetNumPosition) {
                ansIdx = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if(ansIdx == -1) {
            currNumLeftIdx = nums.size();
            return -1;
        }

        currNumLeftIdx = ansIdx;
        return nums[ansIdx];

    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */