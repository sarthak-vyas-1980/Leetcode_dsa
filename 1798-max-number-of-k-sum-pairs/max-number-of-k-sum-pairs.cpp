class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int count = 0;
        
        for(int i=0; i<nums.size(); i++){
            map[nums[i]]++;
        }
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == k - nums[i]){
                if(map[nums[i]] > 1){
                    count++;
                    map[nums[i]] = map[nums[i]] - 2;
                }
            } 
            else if(map.count(k-nums[i]) && map[nums[i]] > 0 && map[k-nums[i]] > 0){
                count++;
                map[nums[i]]--;
                map[k - nums[i]]--;
            }
        }
        return count;
    }
};