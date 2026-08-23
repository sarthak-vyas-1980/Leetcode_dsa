class Solution {
    bool solve(string& s, string& p, int i, int j, vector<vector<int>>& dp){
        if(j == p.length()) return i == s.length();
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        bool match = i<s.length() && (s[i] == p[j] || p[j] == '.');
        
        if(j+1<p.length() && p[j+1] == '*'){
            bool take = false;
            if(match) take = solve(s, p, i+1, j, dp);
            bool notTake = solve(s, p, i, j+2, dp);
            ans = take || notTake;
        }
        else if(match) ans = solve(s, p, i+1, j+1, dp);;
        return dp[i][j] = ans;
    }
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length()+1, vector<int>(p.length()+1, -1));
        return solve(s, p, 0, 0, dp);
    }
};