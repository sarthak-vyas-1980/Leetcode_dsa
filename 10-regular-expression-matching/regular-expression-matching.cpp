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
        vector<bool> curr(p.length()+1, 0);
        vector<bool> next(p.length()+1, 0);
        next[p.length()] = true;

        for(int i=s.length(); i>=0; i--){
            curr[p.length()] = (i == s.length());
            for(int j=p.length()-1; j>=0; j--){
                bool match = i<s.length() && (s[i] == p[j] || p[j] == '.');
                
                if(j+1<p.length() && p[j+1] == '*'){
                    bool take = false;
                    if(match) take = next[j];
                    bool notTake = curr[j+2];
                    curr[j] = take || notTake;
                }
                else if(match) curr[j] = next[j+1];
                else curr[j] = false;
            }
            next = curr;
        }
        return next[0];
    }
};