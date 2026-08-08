class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<vector<int>,int> thingy;
        for(string s : strs){
            vector<int> letters(26,0);
            for(char c : s) letters[c-'a']++;
            if(thingy.contains(letters)) ans[thingy[letters]].push_back(s);
            else{
                thingy[letters] = ans.size();
                ans.push_back({s});
            }
        }

        return ans;
    }
};
