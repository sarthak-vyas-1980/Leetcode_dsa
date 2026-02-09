class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //Brute force soln: Hashmap
        //Optimisation: Voting system
        int n = nums.size();
        if(nums.size()<2) return nums;
        int candidate1 = 0;
        int candidate2 = 0;
        int vote1=0, vote2=0;
        for(int i=0; i<nums.size(); i++){
            if(candidate1==nums[i]) vote1++;
            else if(candidate2==nums[i]) vote2++;
            else if(!vote1){
                candidate1 = nums[i];
                vote1++;
            } 
            else if(!vote2){
                candidate2 = nums[i];
                vote2++;
            }
            else {
                vote1--;
                vote2--;
            } 
        }
        vote1 = 0;
        vote2 = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==candidate1) vote1++;
            else if(nums[i]==candidate2) vote2++;
        }
        vector<int> ans;
        if (vote1 > n/3) ans.push_back(candidate1);
        if (vote2 > n/3) ans.push_back(candidate2);
        return ans;
    }
};