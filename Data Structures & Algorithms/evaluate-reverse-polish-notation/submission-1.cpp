class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;

        for(string token : tokens){
            if(token == "+"){
                int rightNum = stack.top();
                stack.pop();
                int leftNum = stack.top();
                stack.pop();
                stack.push(rightNum+leftNum);
            }
            else if(token == "-"){
                int rightNum = stack.top();
                stack.pop();
                int leftNum = stack.top();
                stack.pop();
                stack.push(leftNum-rightNum);
            }
            else if(token == "*"){
                int rightNum = stack.top();
                stack.pop();
                int leftNum = stack.top();
                stack.pop();
                stack.push(leftNum*rightNum);
            }
            else if(token == "/"){
                int rightNum = stack.top();
                stack.pop();
                int leftNum = stack.top();
                stack.pop();
                stack.push(leftNum/rightNum);
            }
            else stack.push(stoi(token));

        }

        return stack.top();
    }
};
