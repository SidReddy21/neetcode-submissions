class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,int> map;
        for(string s : strs){
            vector<int> letters(26,0);
            for(char c : s) letters[c-'a']++;
            string compact = "";
            for(int letter : letters) compact+=(to_string(letter)+";");
            if(map.contains(compact)) ans[map[compact]].push_back(s);
            else{
                map[compact] = ans.size();
                ans.push_back({s});
            }
        }

        return ans;
    }
};
