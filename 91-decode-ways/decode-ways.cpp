class Solution {
    int solve(string& s, int index, vector<int>& dp) {  //Top-down Solution
        if (index < 0) return 1;  // valid decoding
        if (dp[index] != -1) return dp[index];

        int ways = 0;
        if (s[index] != '0') {
            ways += solve(s, index - 1, dp);
        }
        if (index > 0) {  //index-1 >= 0
            int num = (s[index - 1] - '0') * 10 + (s[index] - '0');
            if (num >= 10 && num <= 26) {
                ways += solve(s, index - 2, dp);
            }
        }
        return dp[index] = ways;
    }
public:
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        int two = 1, one = 1;
        
        for(int index=1; index<=s.length(); index++){
            int curr = 0;
            if (s[index-1] != '0') {
                curr += one;
            }
            if (index > 1) {  //index-2 >= 0
                int num = (s[index - 2] - '0') * 10 + (s[index-1] - '0');
                if (num >= 10 && num <= 26) {
                    curr += two;
                }
            }
            two = one;
            one = curr;
        }
        return one;

        //Tabulation:
        // if(s[0]=='0') return 0;
        // vector<int> dp(s.length()+1, 0);
        // dp[0] = 1;
        
        // for(int index=1; index<=s.length(); index++){
        //     int ways = 0;
        //     if (s[index-1] != '0') {
        //         ways += dp[index-1];
        //     }
        //     if (index > 1) {  //index-2 >= 0
        //         int num = (s[index - 2] - '0') * 10 + (s[index-1] - '0');
        //         if (num >= 10 && num <= 26) {
        //             ways += dp[index-2];
        //         }
        //     }
        //     dp[index] = ways;
        // }
        // return dp[s.length()];
    }
};