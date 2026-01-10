class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, list<pair<int, double>>> adj;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<double> dist(n, 0.0);
        priority_queue<pair<double,int>> pq; // max-heap
        dist[start_node] = 1.0;
        pq.push({1.0, start_node});
        while (!pq.empty()) {
            auto [prob, node] = pq.top();
            pq.pop();
            if (prob < dist[node]) continue; // stale state
            for (auto &[next, weight] : adj[node]) {
                double newProb = prob * weight;
                if (newProb > dist[next]) {
                    dist[next] = newProb;
                    pq.push({newProb, next});
                }
            }
        }
        return dist[end_node]==INT_MIN ? 0 : dist[end_node];
    }
};