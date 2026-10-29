class StockSpanner {
public:
    stack<int> st;
    vector<int> prices;
    int i=0;

    StockSpanner() {

    }

    int next(int price) {
        prices.push_back(price);

        while(!st.empty() && prices[st.top()]<=price){  //removing smaller prices than price and keeping the prev greater element
            st.pop();
        }

        int span;

        if(st.empty()){
            span=i+1;
        }else{
            span=i-st.top();
        }

        st.push(i);
        i++;

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */