class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size(), pivot);
        int i = 0, j = nums.size()-1;

        for(int index=0; index<nums.size(); index++){
            if((nums[index] < pivot)) ans[i++] = nums[index];

            if(nums[nums.size()-index-1] > pivot) ans[j--] = nums[nums.size()-index-1];
        }
        return ans;
    }
};