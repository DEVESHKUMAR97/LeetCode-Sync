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
    TreeNode* lca;
public:
    bool find(TreeNode* root, int s, int e) {
        if(root == nullptr) return false;
        bool curr = ((root -> val == s) || (root -> val == e));
        bool leftAns = find(root -> left, s, e);
        bool rightAns = find(root->right, s, e);
        if((leftAns && rightAns) || (leftAns && curr) || (rightAns && curr)) {
            lca = root;
            return true;
        }
        return (curr || leftAns || rightAns);
    }
    bool findPath(TreeNode* root, int targetVal, string& path) {
        if(root == nullptr) return false;
        if(root->val == targetVal) return true;
        path.push_back('L');
        if(findPath(root->left, targetVal, path)) return true;
        path.pop_back();

        path.push_back('R');
        if(findPath(root->right, targetVal, path)) return true;
        path.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int s, int e) {
        lca = nullptr;
        find(root, s, e);
        string sToLCAPath = "", eToLCAPath = "";
        findPath(lca, s, sToLCAPath);
        findPath(lca, e, eToLCAPath);
        sToLCAPath = string(sToLCAPath.length(), 'U');
        return sToLCAPath + eToLCAPath;
    }
};