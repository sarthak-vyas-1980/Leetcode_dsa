class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, list<pair<int, int>>> adj;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        int answer = -1;
        int min = INT_MAX; 

        for(int i=0; i<n; i++){
            vector<int> dist(n, INT_MAX);
            set<pair<int,int>> st;
            st.insert({0, i});
            dist[i] = 0;
            while(!st.empty()){
                auto temp = *(st.begin());
                st.erase(st.begin());
                int node = temp.second;
                int distance = temp.first;
                for(auto i: adj[node]){
                    if(distance+i.second < dist[i.first]){
                        // auto record = st.find({dist[i.first],i.first});
                        // if(record!=st.end()) st.erase(record);
                        dist[i.first] = distance + i.second;
                        st.insert({dist[i.first],i.first});

                    }
                }
            }
            int count = 0;
            for(int j=0; j<n; j++){
                if(j!=i && dist[j]<=distanceThreshold) count++;
            }
            if(min >= count){
                min = count;
                answer = i;
            }
        }
        return answer;
    }
};