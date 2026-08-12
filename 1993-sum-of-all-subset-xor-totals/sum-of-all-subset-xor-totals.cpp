class Solution {
    int ans;
    void solve(vector<int>& nums, int ind, int xorr){
        if(ind == nums.size()) return;
        for(int i=ind; i<nums.size(); i++){
            xorr ^= nums[i];
            ans += xorr;
            solve(nums, i+1, xorr);
            xorr ^= nums[i];
        }
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int xorr = 0;
        ans = 0;
        solve(nums, 0, 0);
        return ans;
    }
};