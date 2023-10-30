class RLEIterator {
    deque<pair<int, int> > nums;
public:
    RLEIterator(vector<int>& encoding) {
        for(int i = 0; i < encoding.size(); i += 2) {
            if(encoding[i] != 0) {
                nums.push_back({encoding[i], encoding[i+1]});
            }
        }
    }
    
    int next(int n) {
        while(nums.size() > 0 && nums.front().first < n) {
            n -= nums.front().first;
            nums.pop_front();
        }
        if(nums.size() == 0) return -1;
        nums.front().first -= n;
        int ans = nums.front().second;
        if(nums.front().first == 0) nums.pop_front();
        return ans;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */