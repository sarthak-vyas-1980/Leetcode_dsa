class Solution {
    int solve(string& s, int index, vector<int>& dp) {
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
        vector<int> dp(s.length(), -1);
        return solve(s, s.length() - 1, dp);
    }
};