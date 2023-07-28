class StockSpanner {
public:
    StockSpanner() {
        
    }
   stack<pair<int,int>>s;
   
    int next(int price) {
      
           int cnt =1;
        while(s.size() and s.top().first<=price)
        {
            cnt+=s.top().second;
            s.pop();
        }
        if(s.size()==0)
        {
               s.push({price,cnt});
            return cnt;
        }

        else if(s.top().first>price) 
        {
               s.push({price,cnt});
            return cnt;
        }
  
        return 9;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */