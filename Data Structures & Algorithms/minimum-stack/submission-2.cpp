class MinStack {
    stack<int> stck;
    stack<int> mins;
    int MIN;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(stck.empty()){
            MIN = val;
            mins.push(val);
            stck.push(val);
        }else{
            MIN = min(val,MIN);
            mins.push(MIN);
            stck.push(val);
        }
    }
    
    void pop() {
        if(stck.empty()) return;
        stck.pop();
        mins.pop();
        if(!mins.empty()) MIN = mins.top();
    }
    
    int top() {
        return stck.top();
    }
    
    int getMin() {
        return mins.top();
    }
};
