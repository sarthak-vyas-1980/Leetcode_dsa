class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, list<pair<int, int>>> adj;
        for(int i=0; i<times.size(); i++){
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        vector<int> dist(n+1);
        for(int i=0; i<=n; i++){
            dist[i] = INT_MAX;
        }
        set<pair<int,int>> st;
        st.insert({0, k});
        dist[k] = 0;
        while(!st.empty()){
            auto temp = *(st.begin());
            st.erase(st.begin());
            int node = temp.second;
            int distance = temp.first;
            for(auto i: adj[node]){
                if(distance+i.second < dist[i.first]){
                    auto record = st.find({dist[i.first],i.first});
                    if(record!=st.end()) st.erase(record);
                    dist[i.first] = distance + i.second;
                    st.insert({dist[i.first],i.first});

                }
            }
        }
        int max = dist[1];
        for(int i=1; i<=n; i++){
            if(dist[i]>max) max = dist[i];
            if(dist[i]==INT_MAX) return -1;
        }
        return max;
    }
};