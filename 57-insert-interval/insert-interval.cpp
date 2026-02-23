class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        if(n==0){
            ans.push_back(newInterval);
            return ans;
        }
        int i = 0;
        while(i<n && newInterval[0] > intervals[i][0]){
            ans.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }
        if(i > 0 && intervals[i-1][1] >= newInterval[0]) {
            ans[i-1][1] = max(newInterval[1], intervals[i-1][1]);
        }
        else {
            ans.push_back({newInterval[0], newInterval[1]});
        }
        int j = ans.size()-1;
        for(; i<n; i++){
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