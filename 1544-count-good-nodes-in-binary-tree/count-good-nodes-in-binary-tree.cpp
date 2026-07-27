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
    int ans;

    void solve(TreeNode* root, int last){
        if(!root) return ;

        if(last <= root->val) ans++;
        last = max(last, root->val);

        solve(root->left, last);
        solve(root->right, last);
    }
public:
    int goodNodes(TreeNode* root) {
        if(!root) return 0;

        ans = 0;
        solve(root, root->val);
        return ans;
    }
};