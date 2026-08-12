class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long num = 0;
        for(int i=0; i<nums.size(); i++) num ^= nums[i];

        int bit = (num&(num-1)) ^ num;
        int b1 = 0, b2 = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] & bit) b1 ^= nums[i];
            else b2 ^= nums[i];
        }
        return {b1, b2};   
    }
};