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
    int heightOfTree(TreeNode* root) {
        if(root == nullptr) return -1;
        int leftHeight = heightOfTree(root->left);
        int rightHeight = heightOfTree(root->right);
        return max(leftHeight, rightHeight) + 1;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int height = heightOfTree(root);
        TreeNode* ans = nullptr;
        function<bool(TreeNode*, int)> containsDeepestNode = [&](TreeNode* root, int currDepth) {
            if(root == nullptr) {
                return false;
            }
            if(currDepth == height) {
                ans = root;
                return true;
            }
            bool isLeftTreeContains = containsDeepestNode(root->left, currDepth + 1);
            bool isRightTreeContains = containsDeepestNode(root->right, currDepth + 1);
            if(isLeftTreeContains && isRightTreeContains) {
                ans = root;
            }
            return isLeftTreeContains || isRightTreeContains;
        };
        containsDeepestNode(root, 0);
        return ans;
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return subtreeWithAllDeepest(root);
    }
};

