class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> duplicate;
        for(int num: nums){
            if(duplicate.find(num) != duplicate.end()) return true;
            else duplicate.insert(num);
        }   
        return false;
    }
};