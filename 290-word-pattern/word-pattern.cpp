class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> leftmap;
        unordered_map<string, char> rightmap;
        int i=0, j=0; 
        while(i<pattern.length() && j<s.length()){
            string path = "";
            while(j<s.length() && s[j]!=' ') path.push_back(s[j++]);
            j++;
            if(leftmap.count(pattern[i])){
                if(leftmap[pattern[i]] != path || rightmap[path] != pattern[i]) return false;
            }
            else{
                if(rightmap[path]) return false;
                leftmap[pattern[i]] = path;
                rightmap[path] = pattern[i];
            }
            i++;
        }
        return i == pattern.length() && j >= s.length();
    }
};