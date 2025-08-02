class Solution {
    bool check(int arr1[26], int arr2[26]){
        for(int i=0; i<26; i++){
            if(arr1[i]!=arr2[i]) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        int arr1[26]={0};
        int arr2[26]={0};
        for(int i=0; i<s1.length(); i++){
            int index=s1[i]-'a';
            arr1[index]++;
        }
        int i=0;
        while( i<s1.length() ){
            int index=s2[i]-'a';
            arr2[index]++;
            i++;
        }
        if(check(arr1, arr2)) return true;

        while(i<s2.length()){
            char newChar=s2[i];
            int index=newChar-'a';
            arr2[index]++;
            char oldChar=s2[i-s1.length()];
            int index2=oldChar-'a';
            arr2[index2]--;
            if(check(arr1, arr2)) return true;
            i++;
        }
        return false;
    }
};