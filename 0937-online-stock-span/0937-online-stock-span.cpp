class StockSpanner {
public:
    StockSpanner() {
        
    }
    stack<pair<int,int>>st;
    int next(int price) {
        int i=1;
        while(st.size() and price>=st.top().first)
        {
            i+=st.top().second;
            st.pop();
        }
       
        if(st.size()==0 or st.top().first>price)  st.push({price,i});
   
        
        return i;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */