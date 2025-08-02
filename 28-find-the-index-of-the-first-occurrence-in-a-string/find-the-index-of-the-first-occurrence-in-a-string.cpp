class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
        // int i=0;
        // int h=haystack.size();
        // int n=needle.size();
        // int count=0;
        // int index=-1;

        // while(i<h && count<n){
        //     if(haystack[i]==needle[count]){
        //         if(count==0){
        //             index=i;
        //         }
        //         if(count<n){
        //             count++;
        //         }
        //         else{
        //             break;
        //         } 
        //     }
        //     else{
        //         count=0;
        //         index=-1;
        //     }
        //     i++;
        // } 
        // if(count==n)
        //     return index;
        // return -1;
    }
};