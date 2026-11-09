class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,int> map;
        vector<vector<string>> ans;
        for(string& str : strs){
            vector<int> letters(26,0);
            for(char& c : str){
                letters[c-'a']++;
            }
            if(!map.contains(letters)){
                map[letters] = ans.size();
                ans.push_back({str});
            }else ans[map[letters]].push_back(str);
        }

        return ans;
    }
};
