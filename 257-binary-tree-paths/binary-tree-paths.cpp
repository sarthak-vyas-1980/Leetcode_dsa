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
    void solve(TreeNode* root, vector<string>& ans, string& path){
        if(!root) return ;
        
        int ogLen = path.length();
        if(!path.empty()) path += "->";
        path += to_string(root->val);

        if(!root->left && !root->right){
            ans.push_back(path); 
        }
        solve(root->left, ans, path);
        solve(root->right, ans, path);
        path.resize(ogLen);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path = "";
        solve(root, ans, path);
        return ans;    
    }
};