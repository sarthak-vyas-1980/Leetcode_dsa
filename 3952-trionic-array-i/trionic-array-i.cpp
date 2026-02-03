class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int i=1; 
        while(i<n && nums[i-1]<nums[i]) i++;
        if(i==1 || i==n) return false;

        while(i<n && nums[i-1]>nums[i]) i++;
        if(i==n) return false;

        while(i<n && nums[i-1]<nums[i]) i++;
        if(i==n) return true;
        return false;
        // if (nums.size() <= 4) return false;
        // if(nums[0]>nums[1]) return false;
        // bool flag1 = true;
        // bool flag2 = false;
        // for(int i=1; i<nums.size(); i++){
        //     if(flag1){
        //         if(nums[i-1]<nums[i]) continue;
        //         else flag1 = false;
        //     }
        //     else {
        //         if(flag2) return false;
        //         if(nums[i-1]<nums[i]){
        //             flag1 = true;
        //             flag2 = true;
        //         }
        //     }
        // }
        // return flag1 && flag2;
    }
};