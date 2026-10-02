class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> map;
        vector<vector<string>> ans;
        for(string s : strs){
            vector<int> letters(26,0);
            for(char c : s){
                letters[c-'a']++;
            }
            string temp;
            for(int x : letters) temp+=x;
            if(map.contains(temp)) ans[map[temp]].push_back(s);
            else{
                map[temp] = ans.size();
                ans.push_back({s});
            }
        }

        return ans;
    }
};
