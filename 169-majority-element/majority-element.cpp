class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int vote = 0;
        for(int i=0; i<nums.size(); i++){
            if(!vote){
                candidate = nums[i];
                vote++;
            }
            else if(candidate == nums[i]) vote++;
            else vote--;
        }
        return candidate;
        // if(nums.size()==0)return -1;
        // unordered_map<int,int>m;

        // for(int i=0;i <nums.size();i++){
        //     m[nums[i]]++;
        // }
        // for(auto i:m){
        //     if(i.second > nums.size()/2){
        //         return i.first;
        //     }    
        // }
        // return -1;

    }
};