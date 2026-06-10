class Solution {
public:
    string reverseStr(string s, int k) {
        if(s.length() < k){ 
            reverse(s.begin(), s.end());
            return s;
        }
        for(int i=0; i<s.length(); i=i+2*k){
            string::iterator endPtr = s.begin() + i + k;
            if(s.length() - i < k) endPtr = s.end();
            reverse(s.begin()+i, endPtr);
        }
        return s;
    }
};