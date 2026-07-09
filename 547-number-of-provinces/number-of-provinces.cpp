class Solution {
    void dfs(unordered_map<int, list<int>>& map, unordered_map<int, bool>& vis, int& ans, int node){
        ans++;
        vis[node] = true;
        for(auto nbr: map[node]){
            if(!vis[nbr]) dfs(map, vis, ans, nbr);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int m = isConnected.size();
        int n = isConnected[0].size();
        unordered_map<int, list<int>> map;
        unordered_map<int, bool> vis;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]){
                    map[i].push_back(j);
                    map[j].push_back(i);
                }
            }
        }

        int count = 0, ans = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                count++;
                dfs(map, vis, ans, i);
            }
        }
        return count + (n - ans);
    }
};