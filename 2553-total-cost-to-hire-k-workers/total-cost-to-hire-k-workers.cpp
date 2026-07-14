class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        int i = -1, j = costs.size();
        long long ans = 0;

        for(int m=0; m<candidates && i+1<j; m++){
            pq1.push(costs[++i]);
            if(i+1 == j) break;
            pq2.push(costs[--j]);
        }

        for(int m=0; m<k; m++){
            if(!pq1.empty() && (pq2.empty() || pq1.top() <= pq2.top())){
                ans += pq1.top();
                pq1.pop();

                if(i + 1 < j){
                    pq1.push(costs[++i]);
                }
            }
            else{
                ans += pq2.top();
                pq2.pop();

                if(i + 1 < j){
                    pq2.push(costs[--j]);
                }
            }
        }
        return ans;
    }
};