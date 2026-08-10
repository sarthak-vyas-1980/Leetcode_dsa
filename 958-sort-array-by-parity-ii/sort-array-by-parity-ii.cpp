class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i=0, j=1, i1=0, j1=1;

        while(i<nums.size()){
            if(nums[i]&1){
                while(i1 < nums.size() && (nums[i1]&1)) i1++;
                swap(nums[i], nums[i1]);
            }
            i += 2;
            if(i1 < i) i1 = i;
  
            if((nums[j]&1) == 0){
                while(j1 < nums.size() && (nums[j1]&1) == 0) j1++;
                swap(nums[j], nums[j1]);
            }
            j += 2;
            if(j1 < j) j1 = j;
        }   
        return nums;
    }
};