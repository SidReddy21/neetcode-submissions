class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stck;
        for(string token : tokens){
            if(token == "+"){
                int num1 = stck.top();
                stck.pop();
                int num2 = stck.top();
                stck.pop();
                stck.push(num1+num2);
            }
            else if(token == "-"){
                int num1 = stck.top();
                stck.pop();
                int num2 = stck.top();
                stck.pop();
                stck.push(num2-num1);
            }
            else if(token == "*"){
                int num1 = stck.top();
                stck.pop();
                int num2 = stck.top();
                stck.pop();
                stck.push(num1*num2);
            }
            else if(token == "/"){
                int num1 = stck.top();
                stck.pop();
                int num2 = stck.top();
                stck.pop();
                stck.push(num2/num1);
            }
            else stck.push(stoi(token));
        }
        return stck.top();
    }
};
