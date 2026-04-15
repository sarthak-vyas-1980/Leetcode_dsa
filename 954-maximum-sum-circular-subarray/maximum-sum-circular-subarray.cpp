class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int minSum = INT_MAX;
        int maxSum = INT_MIN;
        int totalSum = 0, currSum = 0;

        for(int i=0; i<nums.size(); i++){
            currSum = min(nums[i], currSum+nums[i]);
            totalSum += nums[i];
            minSum = min(minSum, currSum);
        }
        currSum = 0;
        for(int i=0; i<nums.size(); i++){
            currSum = max(nums[i], currSum+nums[i]);
            maxSum = max(maxSum, currSum);
        }
        int curveSum = totalSum - minSum;
        if(maxSum>0) return max(maxSum, curveSum);
        return maxSum;
    }
};