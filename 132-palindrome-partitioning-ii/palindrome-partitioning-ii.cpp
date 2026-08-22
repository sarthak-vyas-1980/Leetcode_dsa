class Solution {
    // int solve(string& s, int ind, vector<vector<bool>>& palinCheck, vector<int>& dp){
    //     if(ind == s.length()) return 0;
    //     if(dp[ind] != -1) return dp[ind];

    //     int ans = INT_MAX;
    //     for(int i=ind; i<s.length(); i++){
    //         if(palinCheck[ind][i]){
    //             ans = min(ans, 1+solve(s, i+1,palinCheck, dp));
    //         }
    //     }
    //     return dp[ind] = ans;
    // }
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n+1, 0);
        vector<vector<bool>> palinCheck(n, vector<bool>(n, false));

        for(int i=n-1; i>=0; i--){
            palinCheck[i][i] = true;
            for(int j=i+1; j<n; j++){
                if(s[i] == s[j] && (j-i < 2 || palinCheck[i+1][j-1])) palinCheck[i][j] = true; 
            }
        }
        // return solve(s, 0, palinCheck, dp) - 1;

        for(int ind=n-1; ind>=0; ind--){
            int ans = INT_MAX;
            for(int i=ind; i<s.length(); i++){
                if(palinCheck[ind][i]){
                    ans = min(ans, 1+dp[i+1]);
                }
            }
            dp[ind] = ans;
        }
        return dp[0] - 1;
    }
};