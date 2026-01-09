class Solution {
    // void dfs(int sum, int count, int dst, unordered_map<int, list<pair<int,int>>>& adj, unordered_map<int, bool>& visited, int node1, vector<pair<int, int>>& ans){
    //     if(node1==dst){
    //         ans.push_back({sum, count});
    //         return ;
    //     }
    //     visited[node1] = true;
    //     for(auto i: adj[node1]){
    //         if(!visited[i.first]){
    //             dfs(sum+i.second, count+1, dst, adj, visited, i.first, ans);
    //         }
    //     }
    //     visited[node1] = false;
    // }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // unordered_map<int, list<pair<int, int>>> adj;
        // for(int i=0; i<flights.size(); i++){
        //     adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        // }
        // unordered_map<int, bool> visited;
        // // unordered_map<int, bool> dfsVis;
        // vector<pair<int, int>> ans;
        // dfs(0, 1, dst, adj, visited, src, ans);
        // if(ans.empty()) return -1;
        // int result = INT_MAX;
        // for(auto i: ans){
        //     if(i.second<=k+2){
        //         result = min(result, i.first);
        //     }
        // }
        // return result;
        // vector<pair<int, int>> ans;
        int m = flights.size(); 
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        for(int j=0; j<=k; j++){
            vector<int> temp = dist;
            for(int i=0; i<m; i++){
                int u = flights[i][0];
                int v = flights[i][1];
                int w = flights[i][2];
                if(dist[u]!=INT_MAX && dist[u]+w < temp[v]){
                    temp[v] = dist[u] + w;
                }
            }
            dist = temp;
        }
        return dist[dst]==INT_MAX ? -1 : dist[dst];
    }
};