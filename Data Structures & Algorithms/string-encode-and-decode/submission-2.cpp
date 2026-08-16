class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(string s : strs){
            ans+=(to_string(s.size()) + "#" + s);
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string num = "";
        string temp = "";
        for(int i = 0; i < s.size(); i++){
            if(isdigit(s[i])){
                num+=s[i];
                continue;
            }
            if(s[i] == '#'){
                i++;
                int end = stoi(num) + i;
                for(; i < end; i++){
                    temp+=s[i];
                }
                ans.push_back(temp);
                temp = "";
                num = "";
                i--;
            }
        }
        return ans;
    }
};
