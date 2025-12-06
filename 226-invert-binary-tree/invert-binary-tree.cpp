class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;

        // Swap the subtrees
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // Recurse on children
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
