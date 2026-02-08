class Solution {
public:
    int uniquePaths(int m, int n){ 
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m-1][n-1] = 1;

        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                int right=0, down=0;
                if(i+1<m){
                    dp[i][j] += dp[i+1][j];
                }
                if(j+1<n){
                    dp[i][j] += dp[i][j+1];
                }
            }
        }
        return dp[0][0];
    }
};
// class Solution {
//     int solve(int m, int n, vector<vector<bool>>& vis){
//         //memoize it!!!
//         if(m==vis.size()-1 && n==vis[0].size()-1) return 1;
//         if(m<0 || n<0 || m>=vis.size() || n>=vis[0].size()) return 0;

//         vis[m][n] = 1;
//         int right=0, down=0;
//         if(n+1<vis[0].size() && !vis[m][n+1]){
//             right = solve(m, n+1, vis);
//         }
//         if(m+1<vis.size() && !vis[m+1][n]){
//             down = solve(m+1, n, vis);
//         }
//         vis[m][n] = 0;
//         return right+down;
//     }
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<bool>> vis(m, vector<bool>(n, 0));
//         return solve(0, 0, vis);
//     }
// };