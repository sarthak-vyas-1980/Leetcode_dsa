class Solution {
    int solve(int n, vector<int>& dp){
        if(n <=0 ) return 0;
        else if(n == 1 || n == 2) return 1;
        if(dp[n] != -1) return dp[n];

        return dp[n] = solve(n-1, dp) + solve(n-2, dp) + solve(n-3, dp);
    }
public:
    int tribonacci(int n) {
        // vector<int> dp(n+1, -1);
        // return solve(n, dp);

        if(n <=0 ) return 0;
        else if(n == 1 || n == 2) return 1;
        int curr = 0, prev1 = 1, prev2 = 1, prev3 = 0;

        for(int i=3; i<=n; i++){
            curr = prev1 + prev2 + prev3;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};