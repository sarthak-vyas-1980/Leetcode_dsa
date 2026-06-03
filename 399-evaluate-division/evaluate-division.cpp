class Solution {
    double dfs(string& start, string& end, unordered_map<string, vector<pair<string, double>>>& graph, unordered_set<string>& visited){
        if(start == end) return 1.0;
        visited.insert(start);

        for(auto nbr: graph[start]){
            if(!visited.count(nbr.first)){
                double product = dfs(nbr.first, end, graph, visited);
                if(product != -1.0) return product * nbr.second;
            }
        }
        return -1.0; // Path not found
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int m = equations.size();
        unordered_map<string, vector<pair<string, double>>> graph;

        for(int i=0; i<m; i++){
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1.0/values[i]});
        }

        vector<double> ans(queries.size());
        for(int i=0; i<queries.size(); i++){
            string start = queries[i][0], end = queries[i][1];

            if(graph.find(start)==graph.end() || graph.find(end)==graph.end()) {
                ans[i] = (-1.0);
            }else{
                unordered_set<string> visited;
                ans[i] = dfs(start, end, graph, visited);
            }
        }
        return ans;
    }
};