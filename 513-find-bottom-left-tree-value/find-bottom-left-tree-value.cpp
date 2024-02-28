/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);
        int ans = -1;
        for(int level = 0; qu.size() > 0; level++) {
            for(int k = qu.size(); k > 0; k--) {
                TreeNode* curr = qu.front(); qu.pop();
                ans = curr->val;
                if(curr->right) {
                    qu.push(curr->right);
                }
                if(curr->left) {
                    qu.push(curr->left);
                }
            }
        }
        return ans;
    }
};