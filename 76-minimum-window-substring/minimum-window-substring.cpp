class Solution {
    public:
    string minWindow(string s, string t){
        if(t.length() > s.length()) return "";
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for(auto i: t){
            mp2[i]++;
        }
        int i=0, j=0;
        int count = t.length();
        int ansLen = INT_MAX;
        int startIndex = -1;
        while(j<s.length()){
            mp1[s[j]]++;
            if(mp1[s[j]] <= mp2[s[j]]) count--;
            while(count == 0){
                // if(ans.size() > j-i+1 || ans==""){
                //     ans = s.substr(i, j-i+1);
                // }
                if(ansLen > j-i+1){
                    ansLen = j-i+1;
                    startIndex = i;
                }
                mp1[s[i]]--;
                if(mp1[s[i]] < mp2[s[i]]) count++;
                i++;
            }
            j++;
        }
        return ansLen == INT_MAX ? "" : s.substr(startIndex, ansLen);
    }
};

// class Solution {.....................TLE...........................
//     bool compare(unordered_map<char, int> mp1, unordered_map<char, int> mp2){
//         for(auto i: mp2){
//             if(mp1[i.first] < i.second) return false;
//         }
//         return true;
//     }
// public:
//     string minWindow(string s, string t) {
//         if(t.length() > s.length()) return "";
//         unordered_map<char, int> mp1;
//         unordered_map<char, int> mp2;
//         for(auto i: t){
//             mp2[i]++;
//         }
//         string ans = "";
//         int i = 0, j =0;
//         while(j<s.length()){
//             mp1[s[j]]++;
//             while(j-i+1 >= mp2.size() && compare(mp1, mp2)){
//                 if(ans.size() > j-i+1 || ans == "") ans = s.substr(i, j-i+1);
//                 mp1[s[i]]--;
//                 i++;
//             }
//             j++;
//         }
//         return ans;
//     }
// };