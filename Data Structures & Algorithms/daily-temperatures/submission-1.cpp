class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stack;
        stack.push(0);
        vector<int> ans(temperatures.size(),0);

        for(int i = 1; i < temperatures.size(); i++){
            while(!stack.empty() && temperatures[i] > temperatures[stack.top()]){
                ans[stack.top()] = (i-stack.top());
                stack.pop();
            }
            stack.push(i);
        }
        while(!stack.empty()){
            ans[stack.top()] = 0;
            stack.pop();
        }
        return ans;
    }
};
