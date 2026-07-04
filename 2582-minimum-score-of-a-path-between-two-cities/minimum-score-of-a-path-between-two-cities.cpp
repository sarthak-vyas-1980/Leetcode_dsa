class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, list<pair<int, int>>> map;
        unordered_map<int, bool> vis;
        int ans = INT_MAX;

        for(auto road: roads){
            map[road[0]].push_back({road[1], road[2]});
            map[road[1]].push_back({road[0], road[2]});
        }

        queue<int> q;
        q.push(1);
        vis[1] = true;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto i: map[node]){
                ans = min(ans, i.second);
                if(!vis[i.first]){
                    q.push(i.first);
                    vis[i.first] = true;
                }
            }
        }
        return ans;
    }
};