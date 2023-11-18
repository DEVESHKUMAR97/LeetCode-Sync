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
// struct Response {
//     bool isComplete;
//     int height;
//     bool isLeftRightHeightSame;
//     Response(bool isComplete, int height, bool isLeftRightHeightSame):
//     isComplete(isComplete), height(height), isLeftRightHeightSame(isLeftRightHeightSame){}
// };
// class Solution {
//     Response isCompleteTreeAndHeight(TreeNode* root) {
//         if(root == nullptr) return new Response(true, -1, true);
//         auto leftAns = isCompleteTreeAndHeight(root->left);
//         auto rightAns = isCompleteTreeAndHeight(root->right);
        
//         bool isComplete = leftAns.isComplete && rightAns.isComplete && (leftAns.height == rightAns.height || leftAns.height == rightAns.height + 1);
//         int height = max(leftAns.second, rightAns.second) + 1;
//         return {isComplete, height};
//     }
// public:
//     bool isCompleteTree(TreeNode* root) {
//         return isCompleteTreeAndHeight(root).first;
//     }
// };



class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(q.size() > 0) {
            TreeNode* u = q.front(); q.pop();
            if(u == nullptr) {
                while(q.size() > 0) {
                    if(q.front() != nullptr) return false;
                    q.pop();
                }
                return true;
            }
            q.push(u->left);
            q.push(u->right);
        }
        return true; // never execute
    }
};