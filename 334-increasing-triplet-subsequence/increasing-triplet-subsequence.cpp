class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = nums[0], second = INT_MIN;

        for(int i=1; i<nums.size(); i++){
            if(second == INT_MIN && nums[i] < first) first = nums[i]; 
            else if(second == INT_MIN && nums[i] > first) second = nums[i];
            else if(second != INT_MIN && nums[i] > second) return true;
            else if(second != INT_MIN && nums[i] < second){
                if(nums[i] > first) second = nums[i];
                else first = nums[i];
            } 
        }
        return false;
    }
};