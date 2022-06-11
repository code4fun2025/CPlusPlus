class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, nullptr, nullptr);
    }
    
private:
    bool isValidBST(TreeNode* root, int* min_val, int* max_val) {
        if (!root)
            return true;
        if ((min_val && root->val <= *min_val) ||
            (max_val && root->val >= *max_val))
            return false;
        
        return isValidBST(root->left, min_val, &root->val) &&
               isValidBST(root->right, &root->val, max_val);
    }
};
