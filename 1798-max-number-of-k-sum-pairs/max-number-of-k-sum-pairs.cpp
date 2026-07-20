class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<bool> map(nums.size(), 0);
        int i = 0, j = nums.size()-1, count = 0;
        
        while(true){
            bool flag = false;
            while(i < j){
                while(i < nums.size() && map[i]) i++;
                while(j >= 0 && map[j]) j--;
                if(i < nums.size() && j >= 0 && i < j && nums[i] + nums[j] == k){
                    count++;
                    map[i] = map[j] = true;
                    flag = true;
                }
                else if(i < nums.size() && j >= 0 && nums[i] + nums[j] < k) i++;
                else j--;
            }
            if(!flag) break;
            i = 0;
            j = nums.size()-1;
        }
        return count;
    }
};