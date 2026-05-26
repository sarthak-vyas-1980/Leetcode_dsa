class Solution {
    bool solveMem(vector<int>& nums, int& sum, int index, int val, vector<vector<int>>& dp){
        if(index >= nums.size() && sum/2 == val) return true;
        if(index >= nums.size() && sum/2 != val) return false;
        if(dp[index][val] != -1) return dp[index][val];

        bool take = solveMem(nums, sum, index+1, val + nums[index], dp); 
        bool notTake = solveMem(nums, sum, index+1, val, dp); 
        return dp[index][val] = take || notTake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num: nums) sum += num;
        if(sum%2 == 1) return false;

        // vector<vector<int>> dp(nums.size()+1, vector<int>(sum+1, -1));
        // return solveMem(nums, sum, 0, 0, dp);

        vector<vector<bool>> dp(nums.size()+1, vector<bool>((sum/2)+1, 0));
        for(int i=0; i<=nums.size(); i++) dp[i][0] = 1;

        for(int index=nums.size()-1; index>=0; index--){
            for(int val=1; val<=sum/2; val++){ 
                bool take = 0;
                if(val-nums[index]>=0) take = dp[index+1][val-nums[index]];
                bool notTake = dp[index+1][val];
                dp[index][val] = take || notTake;
            }
        }
        return dp[0][sum/2];
    }
};