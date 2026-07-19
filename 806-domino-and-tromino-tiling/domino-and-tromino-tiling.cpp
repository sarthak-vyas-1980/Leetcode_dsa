class Solution {
    int mod = 1e9 + 7;

    int solve(int n, vector<long long>& dp){
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(n == 3) return 5;
        if(dp[n] != -1) return dp[n];

        long long one = (2 * solve(n-1, dp)) % mod;
        long long three = 0;
        if(n > 2) three = solve(n-3, dp) % mod;

        return dp[n] = (one + three) % mod;
    }
public:
    int numTilings(int n) {
        // vector<long long> dp(n+1, -1);
        // return solve(n, dp);

        if(n == 1) return 1;
        if(n == 2) return 2;
        if(n == 3) return 5;
        vector<long long> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        for(int i=4; i<=n; i++){
            long long one = (2 * dp[i-1]) % mod;
            long long three = dp[i-3] % mod;
            dp[i] = (one + three) % mod;
        }
        return dp[n];

    }
};