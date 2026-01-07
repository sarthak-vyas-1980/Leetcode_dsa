class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adj;
        for(int i=0; i<prerequisites.size(); i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[u].push_back(v);
        }
        unordered_map<int, int> inedge(numCourses);
        for(auto i: adj){
            for(auto j: i.second){
                inedge[j]++;
            }
        }
        int count = 0;
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(inedge[i]==0) q.push(i);
        }
        while(!q.empty()){
            int front = q.front();
            q.pop();
            count++;
            for(auto i: adj[front]){
                inedge[i]--;
                if(inedge[i]==0) q.push(i);
            }
        }
        return count == numCourses;
    }
};