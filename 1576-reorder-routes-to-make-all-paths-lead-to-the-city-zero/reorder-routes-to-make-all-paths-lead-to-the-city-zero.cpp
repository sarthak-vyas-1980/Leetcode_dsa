class Solution {
    void solve(unordered_map<int, list<pair<int, int>>>& adj, int& count, int node, int parent){
        for(auto nbr: adj[node]){
            if(nbr.first != parent){
                if(nbr.second == 1) count++;
                solve(adj, count, nbr.first, node);
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int count = 0;
        unordered_map<int, list<pair<int, int>>> adj;

        for(int i=0; i<n-1; i++){
            adj[connections[i][0]].push_back({connections[i][1], 1});
            adj[connections[i][1]].push_back({connections[i][0], 0}); // fake connection - doesn't exist in real graph
        }

        solve(adj, count, 0, -1);
        return count;
    }
};