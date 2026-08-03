class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
       
        if (root == nullptr) {
            return false;
        }
        
        
        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == root->val;
        }
        
     
        int remainingSum = targetSum - root->val;
        
        // Traverse left and right subtrees
        return hasPathSum(root->left, remainingSum) || hasPathSum(root->right, remainingSum);
    }
};