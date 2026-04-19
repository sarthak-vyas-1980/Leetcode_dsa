class Solution {
    static bool cmp(vector<int> p1, vector<int> p2){
        return p1[0] < p2[0];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        vector<vector<int>> ans;

        ans.push_back(points[0]);
        int i = 1;
        while(i < points.size()){
            if(ans.back()[1] >= points[i][0]){
                ans.back()[1] = min(ans.back()[1], points[i][1]);
            }
            else ans.push_back(points[i]);
            i++;
        }
        return ans.size();
    }
};