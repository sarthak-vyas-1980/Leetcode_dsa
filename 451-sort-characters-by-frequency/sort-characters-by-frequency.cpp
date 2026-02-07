class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> map;
        for(char i:s){
            map[i]++;
        }
        priority_queue<pair<int, char>> pq;
        for(auto i: map){
            pq.push({i.second, i.first});
        }
        int i=0;
        while(!pq.empty()){
            int j = pq.top().first;
            char ch = pq.top().second;
            while(j!=0){
                s[i++] = ch;
                j--;
            }
            pq.pop();
        }
        return s;
    }
};