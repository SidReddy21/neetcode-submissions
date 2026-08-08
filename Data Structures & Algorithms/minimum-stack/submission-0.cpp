class MinStack {
private:
    vector<int> stck = {};
    vector<int> stckMin = {};

public:
    MinStack() {
        
    }
    
    void push(int val) {
        stck.push_back(val);
        if(stckMin.empty() || stckMin.back() > val) stckMin.push_back(val);
        else stckMin.push_back(stckMin.back());
    }
    
    void pop() {
        if(stck.empty()) return;
        stck.pop_back();
        stckMin.pop_back();
    }
    
    int top() {
        return stck.back();
    }
    
    int getMin() {
        return stckMin.back();
    }
};
