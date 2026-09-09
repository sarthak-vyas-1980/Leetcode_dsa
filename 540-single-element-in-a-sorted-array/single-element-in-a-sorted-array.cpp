class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        int mid = i + (j-i)/2;

        while(i <= j){
            if(mid&1){
                if(mid+1 < nums.size() && nums[mid] == nums[mid+1]) j = mid - 1;
                else if(mid-1 >=0 && nums[mid] == nums[mid-1]) i = mid + 1;
                else return nums[mid];
            }
            else{
                if(mid+1 < nums.size() && nums[mid] == nums[mid+1]) i = mid + 1;
                else if(mid-1 >=0 && nums[mid] == nums[mid-1]) j = mid - 1;
                else return nums[mid];
            }
            mid = i + (j-i)/2;
        }
        return -1;
    }
};