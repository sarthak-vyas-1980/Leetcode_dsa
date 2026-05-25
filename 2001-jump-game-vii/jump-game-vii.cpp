class Solution {
    bool solveMem(string s, int& minJump, int& maxJump, int index, vector<int>& dp){
        if(index > s.length()-1) return false;
        if(index == s.length()-1) return true;
        if(dp[index] != -1) return dp[index];

        for(int i=index+minJump; i<=index+maxJump && i<s.length(); i++){
            if(s[i] == '0' && solveMem(s, minJump, maxJump, i, dp)){ 
                dp[index] = 1;
                return true;
            }
        }
        dp[index] = 0;
        return false;
    }
public:
    bool canReach(string s, int minJump, int maxJump) {
        // vector<int> dp(s.length(), -1);
        // return solveMem(s, minJump, maxJump, 0, dp);

        // vector<bool> dp(s.length(), 0);
        // dp[s.length()-1] = 1;

        // for(int index=s.length()-2; index>=0; index--){
        //     if(s[index] == '1') continue;
        //     for(int i=index+minJump; i<=index+maxJump && i<s.length(); i++){
        //         if(s[i] == '0' && dp[i]){ 
        //             dp[index] = 1;
        //             break;
        //         }
        //     }
        // }
        // return dp[0];

        int n = s.length();        // Sliding Window DP - O(n)
        vector<bool> dp(n, 0);
        dp[0] = 1;
        int reachableCount = 0;

        for(int i=1; i<n; i++){
            if(i-minJump>=0) reachableCount += dp[i-minJump];

            if(i-maxJump-1>=0) reachableCount -= dp[i-maxJump-1];

            if(s[i]=='0' && reachableCount>0) dp[i]=true;
        }
        return dp[n-1];
    }
};