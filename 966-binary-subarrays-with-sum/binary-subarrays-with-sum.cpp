class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0, size = nums.size();
        int i = 0, j = 0, sum = 0;

        while(j < size){
            sum += nums[j];
            while(sum > goal) sum -= nums[i++];
            if(sum == goal){
                for(int k=i; k<=j; k++){
                    ans++;
                    if(nums[k]) break;
                }
            }
            j++;
        }
        return ans;
    }
};