class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> ans;

        for(int i=0; i<points.size(); i++){
            int dist = (points[i][0] * points[i][0] + points[i][1] * points[i][1]);
            if(k){
                pq.push({dist, {points[i][0], points[i][1]}});
                k--;
            }
            else if(pq.top().first > dist){ 
                pq.pop();
                pq.push({dist, {points[i][0], points[i][1]}});
            }
        }

        while(!pq.empty()){
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }

        return ans;
    }
};