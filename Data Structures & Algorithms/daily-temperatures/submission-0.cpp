class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> stack; //pair.first = tempreature and pair.second = index
        vector<int> ans(temperatures.size(),0);
        for(int i = temperatures.size()-1; i >= 0; i--){

            while(!stack.empty()){
                if(stack.top().first > temperatures[i]){
                    ans[i] = stack.top().second-i;
                    break;
                }
                else stack.pop();
            }
            /*
            nothing
            28
            40
            35,40
            36,40
            */

            stack.push({temperatures[i],i});

        }

        return ans;

    }
};