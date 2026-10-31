class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both nodes are null, they are identical
        if (!p && !q) {
            return true;
        }
        // If one is null and the other is not, or values don't match
        if (!p || !q || p->val != q->val) {
            return false;
        }
        
        // Recursively compare left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};