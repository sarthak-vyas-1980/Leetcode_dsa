class Solution {
    bool solve(string& s, string& p, int i, int j, vector<vector<int>>& dp){
        if(i == 0 && j == 0) return true;
        if(i == 0 && j > 0){
            while(j > 0){
                if(p[j-1] != '*') return false;
                j--;
            }
            return true;
        }
        if(i > 0 && j == 0) return false;
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i-1] == p[j-1] || p[j-1] == '?') return dp[i][j] = solve(s, p, i-1, j-1, dp);
        else if(p[j-1] == '*') return dp[i][j] = solve(s, p, i, j-1, dp) || solve(s, p, i-1, j, dp);
        else return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        // vector<vector<int>> dp(s.length()+1, vector<int>(p.length()+1, -1));
        // return solve(s, p, s.length(), p.length(), dp);

        vector<int> prev(p.length()+1, 0);
        vector<int> curr(p.length()+1, 0);
        prev[0] = 1;

        for(int i=1; i<=p.length(); i++){
            prev[i] = prev[i-1] && p[i-1] == '*';
        }

        for(int i=1; i<=s.length(); i++){
            for(int j=1; j<=p.length(); j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?') curr[j] = prev[j-1];
                else if(p[j-1] == '*') curr[j] = curr[j-1] || prev[j];
                else curr[j] = false;
            }
            prev = curr;
        }
        return prev[p.length()];
    }
};