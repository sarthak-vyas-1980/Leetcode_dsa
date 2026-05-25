class Solution {
    int solve(vector<int>& nums, int index, vector<int>& dp){
        if(index == nums.size()-1) return 0;
        if(index >= nums.size()) return INT_MAX;
        if(dp[index] != -1) return dp[index];

        int ans = INT_MAX;
        for(int i=1; i<=nums[index]; i++){
            int jump = solve(nums, index+i, dp);
            if(jump != INT_MAX){
                ans = min(ans, jump + 1);
            }
        }
        dp[index] = ans;
        return ans;
    }
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size()+1, - 1);
        return solve(nums, 0, dp);
    }
};