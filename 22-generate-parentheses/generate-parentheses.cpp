class Solution {
    void solve(int n, string &path, vector<string> &ans, int i, int j){
        if(i==n && j==n){
            ans.push_back(path);
        }
        if(i<n){
            path.push_back('(');
            solve(n, path, ans, i+1, j);
            path.pop_back();
        }
        if(j<n && i>j){
            path.push_back(')');
            solve(n, path, ans, i, j+1);
            path.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string path;
        // string path="";
        solve(n, path, ans, 0, 0);
        return ans;
    }
};