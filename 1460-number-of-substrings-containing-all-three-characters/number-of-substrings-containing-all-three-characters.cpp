class Solution {
public:
    int numberOfSubstrings(string s) {
        int arr[3] = {0, 0, 0};
        int i = 0, j = 0;
        int ans = 0, n = s.length();

        while(j < n){
            arr[s[j]-'a']++;

            while(arr[0] && arr[1] && arr[2]){
                ans += n - j;
                arr[s[i] - 'a']--;
                i++;
            }
            j++;
        }
        return ans;
    }
};