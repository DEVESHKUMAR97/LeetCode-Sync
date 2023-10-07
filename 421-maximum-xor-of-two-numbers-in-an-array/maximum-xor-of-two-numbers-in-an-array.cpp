class Solution {
public:
    class Trie {
        public:
            Trie* left;
            Trie* right;
        // Trie() {
        //     left = NULL;
        //     right = NULL;
        // }
    };
    Trie* root = NULL;
    void insert(int num) {
        int bitIndex = 30;
        Trie* curr = root;
        
        while(bitIndex >= 0) {
            int mask = 1 << bitIndex;
            int bit = (num & mask) > 0 ? 1 : 0;

            if(bit == 0) {
                if(curr -> left == NULL) {
                    curr -> left = new Trie();
                }
                curr = curr -> left;
            } else {
                if(curr -> right == NULL) {
                    curr -> right = new Trie();
                }
                curr = curr -> right;
            }

            bitIndex--;
        }
    }
    int closestToFind(int find) {
        int bitIndex = 30;
        int ans = 0;
        Trie* curr = root;
        while(bitIndex >= 0) {
            int mask = 1 << bitIndex;
            int desiredBit = (mask & find) > 0? 1: 0;
            if(desiredBit == 1) {
                if(curr->right != NULL) {
                    // desired bit 1 is possible to make. So, set this bit to 1 in ans;
                    ans = ans | mask;
                    curr = curr -> right;
                } else {
                    // desired bit 1 is not possible to make. So, we can only go a head with 
                    // 0 bit, which is already 0 in ans
                    curr = curr -> left;
                }
            } else {
                if(curr->left != NULL) {
                    // desired bit 0 is possible to make, which is already set to 0 in ans;
                    curr = curr -> left;
                } else {
                    // desired bit 0 is not possible to make. So, we can only go a head with 
                    // 1 bit, which we need to set in ans
                    ans = ans | mask;
                    curr = curr -> right;
                }
            }

            bitIndex--;
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        root = new Trie();
        for(int num : nums) {
            insert(num);
        }

        int ans = 0;
        
        for(int a: nums) {
            int find = INT_MAX ^ a;
            // int find = ~a;
            int b = closestToFind(find);
            ans = max(ans, a ^ b);
        }
        return ans;
    }
};