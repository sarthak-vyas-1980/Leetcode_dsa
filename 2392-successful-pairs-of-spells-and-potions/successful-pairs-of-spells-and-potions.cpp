class Solution {
    int lowest(int spell, vector<int>& potions, long long& success){
        int s = 0, e = potions.size()-1;
        int mid = s + (e-s)/2, ans = e+1;

        while(s<=e){
            long long product = (long long)potions[mid] * spell;
            if(product >= success){
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
            mid = s + (e-s)/2;
        }
        return ans;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans(spells.size(), 0);

        for(int i=0; i<spells.size(); i++){
            ans[i] = potions.size() - lowest(spells[i], potions, success);
        }
        return ans;
    }
};