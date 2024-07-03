class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;

        // Recursively invert the left and right subtrees
        TreeNode* right = invertTree(root->right);
        TreeNode* left = invertTree(root->left);

        // Swap the left and right pointers
        root->left = right;
        root->right = left;

        return root;
    }
};
