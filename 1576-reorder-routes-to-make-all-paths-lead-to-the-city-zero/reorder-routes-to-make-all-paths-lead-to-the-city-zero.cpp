class Solution {
    void solve(unordered_map<int, list<int>>& adj, unordered_map<int, list<int>>& real, int& count, int node, int parent){
        // vis[node] = true;
        for(auto nbr: real[node]){
            if(nbr != parent) count++;
        }
        for(auto nbr: adj[node]){
            if(nbr != parent) solve(adj, real, count, nbr, node);
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int count = 0;
        unordered_map<int, list<int>> adj;
        unordered_map<int, list<int>> real;
        // vector<bool> vis(n, 0);

        for(int i=0; i<n-1; i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            real[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        solve(adj, real, count, 0, -1);
        return count;
    }
};