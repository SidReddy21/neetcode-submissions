class Solution {
public:
    int compress(vector<char>& chars) {
        char prev = chars[0];
        int count = 1;
        string ans = "";
        for(int i = 1; i < chars.size(); i++){
            if(prev == chars[i]) count++;
            else if(count > 1){
                ans+=(string(1,prev)+to_string(count));
                prev = chars[i];
                count = 1;
            }else{
                ans+=(string(1,prev));
                prev = chars[i];
            }
        }

        if(count > 1) ans+=(string(1,prev)+to_string(count));
        else ans+=(string(1,prev));
        
        for(int i = 0; i < ans.size(); i++) chars[i] = ans[i];
        return ans.size();
    }
};