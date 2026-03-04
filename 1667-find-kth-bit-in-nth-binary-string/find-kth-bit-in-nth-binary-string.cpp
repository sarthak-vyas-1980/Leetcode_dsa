class Solution {
    string S(int n){
        if(n == 1) return "0";
        return S(n-1) + "1" + reverse(S(n-1));
    }
    string reverse(string str){
        int i=0, j=str.length()-1;
        while(i <= j){
            char a = (str[j] == '0') ? '1' : '0';
            char b = (str[i] == '0') ? '1' : '0';
            str[i] = a;
            str[j] = b;
            i++;
            j--;
        }
        return str;
    }
public:
    char findKthBit(int n, int k) {
        string ans = S(n);
        return ans[k-1];
    }
};