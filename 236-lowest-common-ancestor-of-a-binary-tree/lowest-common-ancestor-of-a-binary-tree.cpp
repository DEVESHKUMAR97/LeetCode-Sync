/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca = nullptr;
        function<bool(TreeNode*, TreeNode*, TreeNode*)> find = [&](TreeNode* root, TreeNode* p, TreeNode* q) {
            if(root == nullptr) return false;

            bool isCurr = ((root == p) || (root == q));

            bool isLeft = find(root -> left, p, q);
            bool isRight = find(root -> right, p, q);

            if((isCurr && isLeft) || (isCurr && isRight) || (isLeft && isRight)) {
                lca = root;
            }

            return isCurr || isLeft || isRight;
        };

        find(root, p, q);

        return lca;
        
    }
};