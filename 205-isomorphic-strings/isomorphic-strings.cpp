class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // if(s.lenght()==0 || t.lenght()==0) return false;
        if(s.length()!=t.length()) return false;
        unordered_map<char, char> map;
        unordered_map<char, bool> check;
        for(int i=0; i<s.length(); i++){
            if(!map[s[i]]){
                if(check[t[i]]) return false;
                map[s[i]] = t[i];
                check[t[i]] = true;
            }
            else{
                if(map[s[i]] != t[i]) return false;
            }
        }
        return true;
    }
};