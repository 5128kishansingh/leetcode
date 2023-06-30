class StockSpanner {
public:
    vector<int>v;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
       v.push_back(price);
       int n=v.size();
        // stack<int>st;
        int count=0;
        for(int i=n-1;i>=0;i--){
            if(v[i]<=price)
            // st.push(v[i]);
            count++;
            else break;
        }
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */