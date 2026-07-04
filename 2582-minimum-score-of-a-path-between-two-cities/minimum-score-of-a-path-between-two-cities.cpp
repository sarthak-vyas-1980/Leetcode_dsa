class Solution {
    void dfs(unordered_map<int, list<pair<int, int>>>& map, unordered_map<int, bool>& vis, int& ans, int node){
        vis[node] = true;
        for(auto nbr: map[node]){
            ans = min(ans, nbr.second);
            if(!vis[nbr.first]){
                dfs(map, vis, ans, nbr.first);
            }
        }
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, list<pair<int, int>>> map;
        unordered_map<int, bool> vis;
        int ans = INT_MAX;

        for(auto road: roads){
            map[road[0]].push_back({road[1], road[2]});
            map[road[1]].push_back({road[0], road[2]});
        }

        dfs(map, vis, ans, 1);
        return ans;
    }
};