class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int, list<pair<int, int>>> adj;
        for(int i=0; i<points.size(); i++){
            for(int j=i+1; j<points.size(); j++){
                int dis = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);    
                adj[i].push_back({j, dis});
                adj[j].push_back({i, dis});
            }
        }
        int n = points.size();
        vector<int> key(n);
        vector<int> parent(n);
        vector<bool> mst(n);
        for(int i=0; i<n; i++){
            parent[i] = -1;
            key[i] = INT_MAX;
            mst[i] = false;
        }
        key[0] = 0;
        for(int i=0; i<n; i++){
            int u;
            int min = INT_MAX;
            for(int v=0; v<n; v++){
                if(mst[v]==false && key[v]<min){
                    min = key[v];
                    u = v;
                }
            }
            mst[u] = true;
            for(auto i: adj[u]){
                if(!mst[i.first] && key[i.first]>i.second){
                    key[i.first] = i.second;
                    parent[i.first] = u;
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            ans += key[i];
        }
        return ans;
    }
};