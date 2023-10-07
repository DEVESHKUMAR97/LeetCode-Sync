class Solution {
public:

        bool isPossibleDivide(vector<int> A, int k) {
        map<int, int> c;
        for (int i : A) c[i]++;
        for (auto it : c)
            if (c[it.first] > 0)
                for (int i = k - 1; i >= 0; --i)
                    if ((c[it.first + i] -= c[it.first]) < 0)
                        return false;
        return true;
    }

    // // O(n * log(n)) | O(n)
    // bool isPossibleDivide(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     if(n % k != 0) return false;

    //     int numOfGrps = n / k;

    //     map<int, int> mp;
    //     for(int num: nums) mp[num]++;

    //     for(int i = 0; i < numOfGrps; i++) {
    //         int curr = mp.begin()->first;
    //         for(int j = 0; j < k; j++) {
    //             if(mp.count(curr)) {
    //                 mp[curr]--;
    //                 if(mp[curr] == 0) {
    //                     mp.erase(curr);
    //                 }
    //                 curr++;
    //             } else return false;
    //         }
    //     }
    //     return true;

        
    // }
};