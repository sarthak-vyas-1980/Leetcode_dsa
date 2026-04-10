class Solution {
    void solve(vector<vector<string>> &ans, vector<string> temp, string s, int i, vector<vector<bool>> dp){
        if(i >= s.length()){
            ans.push_back(temp);
            return ;
        }
        for(int ind=i; ind<s.length(); ind++){
            if(dp[i][ind]){
                temp.push_back(s.substr(i, ind - i +1));
                solve(ans, temp, s, ind+1, dp);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        if(s.length() == 0) return ans;

        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        for(int i=0; i<s.length(); i++){
            dp[i][i] = true;
        }

        for(int length = 1; length < s.length(); length++){
            for(int i=0; i+length < s.length(); i++){
                int j = i + length;
                if(s[i]==s[j] && (length == 1 || dp[i+1][j-1])) dp[i][j] = true;
            }
        }
        
        vector<string> temp;
        solve(ans, temp, s, 0, dp);
        return ans;
    }
};


// class Solution {
//     bool palindrome(string s, int i, int j){
//         while(i < j){
//             if(s[i++] != s[j--]) return false;
//         }
//         return true;
//     }
//     void solve(vector<vector<string>> &ans, vector<string> temp, string s, int i){
//         if(i >= s.length()){
//             ans.push_back(temp);
//             return ;
//         }
//         for(int ind=i; ind<s.length(); ind++){
//             if(palindrome(s, i, ind)){
//                 temp.push_back(s.substr(i, ind - i +1));
//                 solve(ans, temp, s, ind+1);
//                 temp.pop_back();
//             }
//         }
//     }
// public:
//     vector<vector<string>> partition(string s) {
//         vector<vector<string>> ans;
//         if(s.length() == 0) return ans;
//         vector<string> temp;
//         solve(ans, temp, s, 0);
//         return ans;
//     }
// };