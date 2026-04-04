class Solution {
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        int count = 0;
        for(int i=0; i<intervals.size(); i++){
            for(int j=i+1; j<intervals.size(); j++){
                if(intervals[i][0] >= intervals[j][0] || (intervals[i][1] == intervals[j][1])){
                    count++;
                    break;
                }
            }
        }
        return intervals.size() - count;
    }
};