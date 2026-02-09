class Solution {
    bool solve(vector<int> &nums, int index, vector<int>& dp){
        if(index==nums.size()-1) return 1;
        if(dp[index]!=-1) return dp[index];

        bool ans = 0;
        for(int i=nums[index]; i>0; i--){
            if(i+index < nums.size()) ans = solve(nums, index+i, dp);
            if(ans) break;
        }
        dp[index] = ans;
        return dp[index];
    }
public:
    bool canJump(vector<int>& nums){
        int index = 0; 
        vector<int> dp(nums.size(), -1);
        solve(nums, index, dp);
        return dp[0];
    }
};