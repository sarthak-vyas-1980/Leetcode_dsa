class Solution {
    void dfs(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, int node, int parent, vector<int>& disc, vector<int>& low, vector<vector<int>>& result, int& timer){
        low[node] = timer;
        disc[node] = timer++;
        visited[node] = true;
        for(auto i: adj[node]){
            if(i==parent) continue;
            if(!visited[i]){
                dfs(adj, visited, i, node, disc, low, result, timer);
                low[node] = min(low[node], low[i]);
                if(low[i]>disc[node]){
                    vector<int> ans;
                    ans.push_back(node);
                    ans.push_back(i);
                    result.push_back(ans);
                }
            }
            else {
                low[node] = min(low[node], disc[i]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int, list<int>> adj;
        unordered_map<int, bool> visited;
        int timer = 0;
        int parent = -1;
        vector<int> disc (n);
        vector<int> low (n);
        vector<vector<int>> result;
        for(int i=0; i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0; i<n; i++){
            disc[i] = -1;
            low[i] = -1;
        }
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(adj, visited, i, parent, disc, low, result, timer);
            }
        }
        return result;
    }
};