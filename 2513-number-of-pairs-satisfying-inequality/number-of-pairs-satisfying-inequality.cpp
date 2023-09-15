#define ll long long
class BIT {
    int n;
    vector<int> bit;

    int lsb(int i) {
        return i & -i;
    }

    public:

    BIT(int maxN) {
        this -> n = maxN+1;
        bit = vector<int> (n, 0);
        // no need to do preprocessing
        // cout << n << endl;
    }

    int queryBIT(int idx) {
        // cout << idx << endl;
        int sum = 0;
        for(int i = idx; i > 0; i -= lsb(i)) {
            sum += bit[i];
        }
        // cout << "sum = " << sum << endl;
        return sum;
    }

    void updateBIT(int idx, int delta) {
        for(int i = idx; i < n; i += lsb(i)) {
            bit[i] += delta;
        }
    }
};


class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        vector<int> diffs(n);

        int smallest = INT_MAX;
        for(int i = 0; i < n; i++) {
            diffs[i] = nums1[i] - nums2[i];
            smallest = min(smallest, diffs[i]);
        }

        smallest -= abs(diff);

        int offset;
        if(smallest > 0) {
            offset = 0; 
        } else {
            offset = abs(smallest) + 1;
        }
        // cout << smallest << endl;
        // cout << offset << endl;

        int mx = *max_element(diffs.begin(), diffs.end());

        BIT bit(mx+offset+abs(diff));
        ll ans = 0;

        for(int j = 0; j < n; j++) {
            ans += bit.queryBIT(diffs[j] + diff + offset);
            bit.updateBIT(diffs[j] + offset, 1);
        }
        return ans;
    }
};