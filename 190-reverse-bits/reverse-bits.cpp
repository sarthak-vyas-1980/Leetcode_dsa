class Solution {
public:
    int reverseBits(int n) {
        string str;
        while(n!=0){
            str.push_back(n%2 + '0');
            n = n/2;
        }
        while(str.length()!=32) str.push_back('0');
        // reverse(str.begin(), str.end());
        int ans = 0;
        int size = str.length();
        for(int i=size-1; i>=0; i--){
            if(str[i]=='1') ans += pow(2, size-i-1);
        }
        return ans;
    }
};