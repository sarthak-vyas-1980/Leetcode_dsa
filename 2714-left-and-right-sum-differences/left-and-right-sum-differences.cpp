class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        for(int i=1; i<n; i++){
            ans[i] = ans[i-1] + nums[i-1];
        }

        int prefix = 0;
        for(int i=n-1; i>=0; i--){
            ans[i] = abs(ans[i] - prefix);
            prefix += nums[i];
        }
        return ans;
    }
};