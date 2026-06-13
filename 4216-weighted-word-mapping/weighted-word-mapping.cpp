class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for(int i=0; i<words.size(); i++){
            int sum = 0;
            for(char ch: words[i]){
                sum += weights[ch - 'a'];
            }
            ans.push_back((25 - (sum % 26)) + 'a');
        }
        return ans;
    }
};