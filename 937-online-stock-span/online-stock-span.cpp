class StockSpanner {
    stack<pair<int, int>> s;

    void solve(stack<pair<int, int>>& s, int last, int& count){
        if(s.empty()) return ;
        int temp = s.top().first;

        if(temp <= last){
            count += s.top().second + 1;
            s.pop();
            solve(s, last, count);
        }  
    }
public:
    StockSpanner() {}
    int next(int price) {
        int count = 1;
        solve(s, price, count);
        s.push({price, count - 1});
        return count;
    }
};