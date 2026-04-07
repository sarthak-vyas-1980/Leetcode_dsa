class Solution {
    static bool cmp(vector<int>& box1, vector<int>& box2){
        return box1[1] > box2[1];
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);

        int ans = 0;
        for(int i=0; i<boxTypes.size(); i++){
            if(truckSize >= boxTypes[i][0]){
                ans += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            else{
                ans += truckSize * boxTypes[i][1];
                break;
            }
        }
        return ans;
    }
};