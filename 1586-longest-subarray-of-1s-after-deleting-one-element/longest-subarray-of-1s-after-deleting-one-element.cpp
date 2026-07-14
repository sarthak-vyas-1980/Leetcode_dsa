class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int start = 0, end = 0, j = 0;
        int ans = 0;

        while(j < nums.size()){
            if(nums[j] == 0){
                ans = j-1;
                end = j++;
                break; 
            }
            j++;
        }
        if(j == nums.size()) return nums.size() - 1;

        while(j < nums.size()){
            if(nums[j] == 0){
                ans = max(ans, j-1-start);
                start = end + 1;
                end = j;
            }
            j++;
        }
        if(nums[j-1] == 1) ans = max(ans, j-start-1);
        return ans;
    }
};