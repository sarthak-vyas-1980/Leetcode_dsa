class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<2) return s;
        vector<vector<bool>> dp(s.length()+1, vector<bool>(s.length()+1, 0));
        int start = 0, end = 0, maxLen = 1;

        for(int i=s.length()-1; i>=0; i--){
            dp[i][i] = true;
            for(int j=i+1; j<s.length(); j++){
                if(s[i]==s[j] && (j-i <= 2 || dp[i+1][j-1])){
                    dp[i][j] = 1;
                    if(maxLen < j-i+1){
                        maxLen = j-i+1;
                        start = i;
                        end = j;
                    }
                }
            }
        }
        return s.substr(start, end-start+1);
    }
};  