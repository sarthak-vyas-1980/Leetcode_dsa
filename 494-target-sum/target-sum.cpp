class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);
        int ofs = 2*sum;
        if(abs(target) > sum) return 0;
        vector<vector<int>> dp(n+1, vector<int>(2*ofs + 1,0));
        dp[0][ofs] = 1; //think this as starting node(0,0) as we start things from ofs 
        for(int i=1; i<=n; i++) {
            for(int j=-sum; j<=sum; j++) {
                dp[i][j + ofs] += dp[i-1][j + nums[i-1] + ofs];
                dp[i][j + ofs] += dp[i-1][j - nums[i-1] + ofs];
                // dp[i][j + nums[i-1] + ofs] += dp[i-1][j + ofs];
                // dp[i][j - nums[i-1] + ofs] += dp[i-1][j + ofs];
            }
        }
        return dp[n][target + ofs];
    }
};

// class Solution {
//     int solve(vector<int>& nums, int target, int sum, int index){
//         if(index==-1 && sum==target) return 1;
//         if(index==-1) return 0;

//         int add = solve(nums, target, sum+nums[index], index-1);
//         int sub = solve(nums, target, sum-nums[index], index-1);
//         return add+sub;
//     }
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         return solve(nums, target, 0, nums.size()-1);
//     }
// };