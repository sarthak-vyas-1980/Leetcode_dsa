class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mp;
        for(int num: arr){
            mp[num] = 1;
        }
        
        int i = 1;
        for(auto& row: mp){
            row.second = i++;
        }
        
        for(int i=0; i<arr.size(); i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};