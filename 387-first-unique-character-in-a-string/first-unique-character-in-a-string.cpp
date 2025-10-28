class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> count;
        queue<int> q;
        for (int i=0; i<s.length(); i++){
            count[s[i]]++;
            q.push(i);
        }
        while(!q.empty() && count[s[q.front()]]>1){
            q.pop();
        }
        if(q.empty()) return -1;
        return q.front();
    }
};