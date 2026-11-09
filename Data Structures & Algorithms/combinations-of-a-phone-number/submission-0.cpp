class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        vector<vector<char>> phone = {{}, {}, {'a','b','c'}, {'d','e','f'}, {'g','h','i'}, {'j','k','l'}, {'m','n','o'}, {'p','q','r','s'}, {'t','u','v'}, {'w','x','y','z'}};
        vector<string> ans = {};
        string temp = "";
        dfs(digits,phone,ans,temp,0);
        return ans;
    }

    void dfs(string& digits,vector<vector<char>>& phone, vector<string>& ans, string& temp, int idx){
        if(idx == digits.size()){
            ans.push_back(temp);
            return;
        }
        for(char c : phone[digits[idx]-'0']){
            temp+=c;
            dfs(digits,phone,ans,temp,idx+1);
            temp.pop_back();
        }
    }
};
