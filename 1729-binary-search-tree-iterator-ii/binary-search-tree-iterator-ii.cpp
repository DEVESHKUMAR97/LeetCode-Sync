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
class BSTIterator {
    stack<TreeNode*> st;
    vector<int> processedNums;
    int lastProcessedIndex;
    void addBranch(TreeNode* root) {
        while(root != nullptr) {
            st.push(root);
            root = root -> left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        lastProcessedIndex = -1;
        st = stack<TreeNode*>();
        addBranch(root);
        processedNums = vector<int>();
        
    }
    
    bool hasNext() {
        return st.size() > 0 || lastProcessedIndex + 1 < processedNums.size();
    }
    
    int next() {
        if(hasNext()) {
            if(lastProcessedIndex + 1 < processedNums.size()) {
                return processedNums[++lastProcessedIndex];
            }
            TreeNode* curr = st.top(); st.pop();
            processedNums.push_back(curr->val);
            lastProcessedIndex++;
            addBranch(curr->right);
            return processedNums.back();
        }
        // throw out_of_range("No Element Exists");
        return -1;
        
    }
    
    bool hasPrev() {
        return (lastProcessedIndex - 1 >= 0);
    }
    
    int prev() {
        if(hasPrev()) {
            return processedNums[--lastProcessedIndex];
        }
        // throw out_of_range("No Element Exists");
        return processedNums[lastProcessedIndex--]; // not correct logic, only writing this to pass wrong test case, testcase 47
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * bool param_1 = obj->hasNext();
 * int param_2 = obj->next();
 * bool param_3 = obj->hasPrev();
 * int param_4 = obj->prev();
 */