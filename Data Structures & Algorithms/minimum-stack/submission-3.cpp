class MinStack {

private:
    stack<int> stck;
    stack<int> stckMin;

public:
    MinStack() {

    }
    
    void push(int val) {
        stck.push(val);
        if(!stckMin.empty()) stckMin.push(min(val,stckMin.top()));
        else stckMin.push(val);
    }
    
    void pop() {
        stck.pop();
        stckMin.pop();
    }
    
    int top() {
        return stck.top();
    }
    
    int getMin() {
        return stckMin.top();
    }
};
