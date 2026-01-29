class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // unordered_map<int, vector<int>> map;
        // for(int i=0; i<nums.size(); i++){
        //     map[nums[i]].push_back(i);
        // }
        // for(auto i: map){
        //     vector<int> arr = i.second;
        //     if(arr.size()==1) continue;
        //     for(int j=1; j<arr.size(); j++){
        //         if(abs(arr[j]-arr[j-1])<=k) return true;
        //     }
        // }
        // return false;
//Since we are accessing only two concurrent indexes at a time for minimun difference, why to maintain an array for that; It's just like converting tabular into space optimisation. 
        unordered_map<int, int> lastIndex;
        for(int i=0; i<nums.size(); i++){
            if(lastIndex.count(nums[i])){
                if(abs(i-lastIndex[nums[i]])<=k) return true;
            }
            lastIndex[nums[i]] = i;
        }
        return false;
    }
};