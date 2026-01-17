class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        unordered_map<int, bool> map;
        int i=0, ans=0;
        while(i<nums.size()){
            if(nums[i]!=target[i]){
                if(!map.count(nums[i])){
                    map[nums[i]] = true;
                    ans++;
                }
            }
            i++;
        }
        return ans;
        // priority_queue<pair<int,int>> pq;
        // for(auto j: count){
        //     pq.push({j.second, j.first});
        // }
        // int n=0;
        // while(nums!=target){
        //     int number = pq.top().second;
        //     pq.pop();
        //     for(int i=0; i<nums.size(); i++){
        //         if(nums[i]==number){
        //             nums[i] = target[i];
        //         }
        //     }
        //     n++;
        // }
        // return n;
    }
};