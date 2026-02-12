class Solution {
public:
    void sortColors(vector<int>& nums) {
        //counting was always an option but not optimized!
        int i = 0;
        int j = i;
        int k = nums.size()-1;

        while(j<=k){
            if(nums[j]==0) {
                swap(nums[i++], nums[j++]);
            }
            else if(nums[j]==2) {
                swap(nums[j],nums[k--]);
            }
            else j++;
        }
    }
};