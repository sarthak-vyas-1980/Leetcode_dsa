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

    void check(TreeNode* root, map<pair<TreeNode*, bool>, bool>& vis, bool r){
        TreeNode* curr;
        if(r) curr = root->right;
        else curr = root->left;
        vis[{root, r}] = true;
        int count = 0;

        while(curr){
            count++;
            r = !r;
            vis[{curr, r}] = true;
            if(r) curr = curr->right;
            else curr = curr->left;
        } 
        ans = max(ans, count);
    }

    void solve(TreeNode* root, map<pair<TreeNode*, bool>, bool>& vis){
        if(!root) return ;
        if(root->left && !vis[{root, 0}]) check(root, vis, 0);
        if(root->right && !vis[{root, 1}]) check(root, vis, 1);
        
        solve(root->left, vis); 
        solve(root->right, vis); 
    }
public:
    int longestZigZag(TreeNode* root) {
        ans = 0;
        map<pair<TreeNode*, bool>, bool> vis;
        solve(root, vis);
        return ans;
    }
};