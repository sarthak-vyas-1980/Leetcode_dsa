class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0;
        int prev1 = nums[0];
        for(int i=1; i<nums.size(); i++){
            int incl = nums[i] + prev2;
            int excl = prev1;
            int ans = max(incl , excl);
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
};