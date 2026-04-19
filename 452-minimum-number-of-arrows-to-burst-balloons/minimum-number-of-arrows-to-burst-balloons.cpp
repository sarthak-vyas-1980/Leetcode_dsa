class Solution {
    static bool cmp(vector<int>& p1, vector<int>& p2){
        return p1[0] < p2[0];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);

        int p = 0;
        int i = 1, ans = 1;
        while(i < points.size()){
            if(points[p][1] >= points[i][0]){
                points[p][1] = min(points[p][1], points[i][1]);
            }
            else{ 
                p = i;
                ans++;
            } 
            i++;
        }
        return ans;
    }
};