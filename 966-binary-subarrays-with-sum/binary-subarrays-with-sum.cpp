class Solution {
public:
    int atMost(vector<int>& nums, int goal) { // Optimized approach
        if (goal < 0) return 0;
        int ans = 0, size = nums.size();
        int i = 0, sum = 0;

        for(int j=0; j<size; j++){
            sum += nums[j];
            while(j >= i && sum > goal) sum -= nums[i++];
            ans += j - i + 1;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal-1);
    }
};