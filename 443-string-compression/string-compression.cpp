#include<unordered_map>
#include<string>
class Solution {
    void recursion(vector<char>& chars,int& i,int count){
        if(count==0) return;
        int digit=count%10;
        recursion(chars, i, count/10);
        char put='0'+digit;
        chars[i++]=put;
    }
public:
    int compress(vector<char>& chars) {
        if(chars.size()<1) return 0;
        if(chars.size()==1) return 1;

        int i=0, j=0;
        while(i<chars.size() && j<chars.size()){
            int k=j+1, count=1;
            chars[i++]=chars[j];
            if(chars[j] == chars[k]){
                while(k<chars.size() && chars[j] == chars[k]){
                    count++;
                    k++;
                }
                recursion(chars, i, count);
                j=k;
            }
            else j++;
        }
        return i;
    }
};