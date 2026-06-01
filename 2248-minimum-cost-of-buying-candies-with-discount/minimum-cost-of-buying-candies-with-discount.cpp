class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(), cost.rend());
        int ans = 0;
        int i = 0;
        while(i < cost.size()){
            ans += cost[i++];
            if(i < cost.size()){
                ans += cost[i++];
            }
            i++;
        }
        return ans;
    }
};