
class MinStack {
public:
    stack<pair<int,int>> s; //val,minval so that we can compare
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){ //no prev minval
            s.push({val,val});
        }else{
            int minval=min(s.top().second,val);//check which is minimum
            s.push({val,minval});
        }
        
    }
    
    void pop() {
        s.pop();  //doesnot match name because one pop is from stack and one is from MinStack
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */