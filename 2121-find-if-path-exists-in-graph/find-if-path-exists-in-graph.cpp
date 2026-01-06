class Solution {
    bool dfs(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, int s, int d){
        visited[s] = true;
        for(auto i: adj[s]){
            if(i==d) return true;
            if(!visited[i]){
                bool ans = dfs(adj, visited, i, d);
                if(ans) return true;
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination && source<n) return true;
        unordered_map<int, list<int>> adj;
        unordered_map<int, bool> visited;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(adj, visited, source, destination);
    }
};