class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int ans = 0;

        while(j<nums.size()){
            if(nums[j] == 0){
                if(k > 0) k--;
                else{
                    while(k == 0) if(nums[i++] == 0) break;
                }
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};