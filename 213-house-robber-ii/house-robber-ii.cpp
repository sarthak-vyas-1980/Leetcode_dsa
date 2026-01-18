class Solution {
    int robbery(vector<int>& nums, int s, int e) {
        int prev2 = 0;
        int prev1 = nums[s];
        for(int i=s+1; i<e; i++){
            int incl = nums[i] + prev2;
            int excl = prev1;
            int ans = max(incl , excl);
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if(n==1) return nums[n-1];
        return max(robbery(nums, 0, n-1), robbery(nums, 1, n));
    }
};