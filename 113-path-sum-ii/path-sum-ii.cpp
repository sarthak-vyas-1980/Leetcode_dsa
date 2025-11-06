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
    void solve(TreeNode* root, int targetSum, vector<vector<int>>& pathSum, int sum, vector<int> path){
        if(root==NULL) return ;
        sum += root->val;
        path.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(targetSum == sum) pathSum.push_back(path);
            return ;
        }
        
        solve(root->left, targetSum, pathSum, sum, path);
        solve(root->right, targetSum, pathSum, sum, path);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path ;
        solve(root, targetSum, ans, 0, path);
        return ans;
    }
};