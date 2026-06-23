class Solution {
    int solve(int n, vector<int>& dp){
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];

        int ans = INT_MAX;
        for(int i=1; i<=100; i++){
            if(n < i*i) break;
            else{
                ans = min(ans, solve(n - i*i, dp) + 1);
            }
        }
        return dp[n] = ans;
    }
public:
    int numSquares(int n) {
        // vector<int> dp(n+1, -1);
        // return solve(n, dp);

        vector<int> dp(n+1, 0);
        for(int num=1; num<=n; num++){
            int ans = INT_MAX;

            for(int i=1; i<=100; i++){
                if(num < i*i) break;
                else{
                    ans = min(ans, dp[num - i*i] + 1);
                }
            }
            dp[num] = ans;
        }
        return dp[n]; 
    }
};