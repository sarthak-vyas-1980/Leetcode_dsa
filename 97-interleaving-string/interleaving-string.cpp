class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()) return false;
        vector<vector<vector<bool>>> dp(s1.length()+1, vector<vector<bool>>(s2.length()+1, vector<bool>(s3.length()+1, 0)));
        dp[s1.length()][s2.length()][s3.length()] = true;

        for(int i=s1.length()-1; i>=0; i--){
            int k = i + s2.length();
            if(s1[i] == s3[k]) dp[i][s2.length()][k] = dp[i+1][s2.length()][k+1];
        }
        for(int j=s2.length()-1; j>=0; j--){
            int k = j + s1.length();
            if(s2[j] == s3[k]) dp[s1.length()][j][k] = dp[s1.length()][j+1][k+1];
        }

        for(int i=s1.length()-1; i>=0; i--){
            for(int j=s2.length()-1; j>=0; j--){
                int k = i + j;
                bool first = false, second = false;
                if(s1[i] == s3[k]) first = dp[i+1][j][k+1];
                if(s2[j] == s3[k]) second = dp[i][j+1][k+1];
                    
                dp[i][j][k] = first || second;
            }
        }
        return dp[0][0][0];
    }
};