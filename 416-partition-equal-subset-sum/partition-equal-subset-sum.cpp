class Solution {
    bool solve(vector<int>& nums, int& sum, int index, int val, vector<vector<int>>& dp){
        if(index >= nums.size() && sum/2 == val) return true;
        if(index >= nums.size() && sum/2 != val) return false;
        if(dp[index][val] != -1) return dp[index][val];

        bool take = solve(nums, sum, index+1, val + nums[index], dp); 
        bool notTake = solve(nums, sum, index+1, val, dp); 
        return dp[index][val] = take || notTake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num: nums) sum += num;
        if(sum%2 == 1) return false;

        vector<vector<int>> dp(nums.size()+1, vector<int>(sum+1, -1));
        return solve(nums, sum, 0, 0, dp);
    }
};