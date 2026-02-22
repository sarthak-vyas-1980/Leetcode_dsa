class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back({intervals[0][0], intervals[0][1]});
        int j = 0;
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] <= ans[j][1]){
                ans[j][0] = ans[j][0];
                ans[j][1] = max(intervals[i][1], ans[j][1]);
            } 
            else {
                ans.push_back({intervals[i][0], intervals[i][1]});
                j++;
            }
        }
        return ans;
    } 
};