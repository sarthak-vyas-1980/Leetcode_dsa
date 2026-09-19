class Solution {
    bool solve(string& s1, string& s2, string& s3, int i, int j, int k, vector<vector<vector<int>>>& dp){
        if(k == s3.length()) return true;
        if(i == s1.length()){
            while(j < s2.length()){
                if(s2[j++] != s3[k++]) return false;
            }
            return k == s3.length();   
        }
        if(j == s2.length()){
            while(i < s1.length()){
                if(s1[i++] != s3[k++]) return false;
            }
            return k == s3.length();
        }
        if(dp[i][j][k] != -1) return dp[i][j][k];

        bool first = false, second = false;
        if(s1[i] == s3[k]) first = solve(s1, s2, s3, i+1, j, k+1, dp);
        if(s2[j] == s3[k]) second = solve(s1, s2, s3, i, j+1, k+1, dp);
        return dp[i][j][k] = first || second;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()) return false;
        vector<vector<vector<int>>> dp(s1.length(), vector<vector<int>>(s2.length(), vector<int>(s3.length(), -1)));
        return solve(s1, s2, s3, 0, 0, 0, dp);
    }
};