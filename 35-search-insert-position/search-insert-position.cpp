class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target<=nums[0]) return 0;
        if(target>nums[nums.size()-1]) return nums.size();
        int s = 0;
        int e = nums.size()-1;
        int mid = s + (e-s)/2;
        while(s<e){
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) s=mid+1;
            else e=mid-1;
            mid = s + (e-s)/2;
        }
        if(nums[s]<target) return s+1;
        return s;
    }
};