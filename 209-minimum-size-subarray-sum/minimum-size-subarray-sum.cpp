class Solution {
    public: 
    int minSubArrayLen(int target, vector<int>& nums){
        int n = nums.size();
        int i = 0, j = 0;
        int ans = INT_MAX; 
        int sum = 0;
        while(j<n){
            sum += nums[j];
            while(sum >= target){
                ans = min(ans, j-i+1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
// class Solution {...............TLE.................
//     bool solve(int target, vector<int>& nums, int k){
//         int sum = 0;
//         for(int i=0; i<k; i++){
//             sum += nums[i];
//         }
//         if(sum >= target) return true;
//         for(int i=k; i<nums.size(); i++){
//             sum += nums[i] - nums[i-k];
//             if(sum >= target) return true;
//         }
//         return false;
//     }
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         for(int i=1; i<=nums.size(); i++){
//             if(solve(target, nums, i)) return i;
//         }
//         return 0;
//     }
// };