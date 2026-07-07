class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char, int> count, check;
        int i = 0, j = 0;

        for(char c: p){
            check[c]++;
        }

        while(j < s.length()){  
            count[s[j++]]++;
            while(j-i < p.length()){
                count[s[j++]]++;
            }
            if(count == check) ans.push_back(i);
            count[s[i]]--;
            if(count[s[i]] == 0) count.erase(s[i]);
            i++;
        }   
        return ans;
    }
};