/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class BSTIterator {
    Stack<TreeNode> st;
    private void addBranch(TreeNode root) {
        TreeNode curr = root;
        while(curr != null) {
            st.push(curr);
            curr = curr.left;
        }

    }

    public BSTIterator(TreeNode root) {
        st = new Stack<>();
        addBranch(root);
    }
    
    public int next() {
        TreeNode curr = st.pop(); 
        addBranch(curr.right);
        return curr.val;
    }
    
    public boolean hasNext() {
        return st.size() > 0;
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */