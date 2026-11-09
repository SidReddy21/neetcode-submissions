class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans = {};
        string temp = "";
        dfs(n,ans,temp,0,0);
        return ans;
    }

    void dfs(int n, vector<string>& ans, string& temp, int open, int close){
        if(open == close && open == n){
            ans.push_back(temp);
            return;
        }

        if(open < n){
            temp.push_back('(');
            dfs(n,ans,temp,open+1,close);
            temp.pop_back();
        }
        if(close < open){
            temp.push_back(')');
            dfs(n,ans,temp,open,close+1);
            temp.pop_back();
        }
    }
};
