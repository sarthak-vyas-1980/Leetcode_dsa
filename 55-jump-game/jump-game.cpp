class Solution {
public:
    bool canJump(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[n-1] = 1;

        for(int i=n-2; i>=0; i--){
            bool ans = 0;
            for(int k=nums[i]; k>0; k--){
                if(k+i < nums.size()) ans = dp[i+k];
                if(ans) break;
            }
            dp[i] = ans;
        }
        return dp[0];
    }
};
// class Solution {
//     bool solve(vector<int> &nums, int index, vector<int>& dp){
//         if(index==nums.size()-1) return 1;
//         if(dp[index]!=-1) return dp[index];

//         bool ans = 0;
//         for(int i=nums[index]; i>0; i--){
//             if(i+index < nums.size()) ans = solve(nums, index+i, dp);
//             if(ans) break;
//         }
//         dp[index] = ans;
//         return dp[index];
//     }
// public:
//     bool canJump(vector<int>& nums){
//         int index = 0; 
//         vector<int> dp(nums.size(), -1);
//         solve(nums, index, dp);
//         return dp[0];
//     }
// };