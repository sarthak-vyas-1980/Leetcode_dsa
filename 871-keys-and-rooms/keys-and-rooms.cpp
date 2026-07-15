class Solution {
    int count;
    void solve(vector<vector<int>>& rooms, unordered_map<int, bool>& vis, int node){
        vis[node] = true;
        for(int i: rooms[node]){
            if(!vis[i]){
                count++;
                solve(rooms, vis, i);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        count = 1;
        unordered_map<int, bool> vis;
        solve(rooms, vis, 0);
        return count == rooms.size();
    }
};