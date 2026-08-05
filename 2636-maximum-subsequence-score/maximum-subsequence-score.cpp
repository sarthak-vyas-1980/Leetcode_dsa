class Solution {
    static bool cmp(pair<int, int>& num1, pair<int, int>& num2){
        if(num1.first == num2.first) return num1.second > num2.second;
        return num1.first > num2.first;
    }
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        long long sum = 0, min, score = 0;
        vector<pair<int, int>> arr;
        priority_queue<int, vector<int>, greater<int>> q;

        for(int i=0; i<n; i++){
            arr.push_back({nums2[i], nums1[i]});
        }
        sort(arr.begin(), arr.end(), cmp);

        for(int i=0; i<n; i++){
            q.push(arr[i].second);
            sum += arr[i].second;

            if(q.size() > k){
                sum -= q.top();
                q.pop();
            }
            if(q.size() == k) score = max(score, arr[i].first*sum);
        }
        return score;
    }
};