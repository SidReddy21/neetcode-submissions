class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(string str : strs){
            ans+=(to_string(str.size()) + "#" + str);
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;

        while(i < s.size()){
            string temp = "";
            int len = 0;

            while(s[i] != '#'){
                len*=10;
                len+=(s[i]-'0');
                i++;
            }

            i++;

            for(int j = i; j < i+len; j++){
                temp+=s[j];
            }

            ans.push_back(temp);
            i+=len;
        }

        return ans;
    }
};
