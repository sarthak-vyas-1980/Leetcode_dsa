class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> count;
        for(int i=0; i<nums.size(); i++){
            count[nums[i]]++;
        }
        int sum = 0;
        for(auto i: count){
            if(i.second==1) sum += i.first;
        }
        return sum;
    }
};