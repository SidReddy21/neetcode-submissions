class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> map;
        vector<vector<string>> ans;
        for(string& str : strs){
            vector<int> temp(26,0);
            for(char& c : str) temp[c-'a']++;
            string letters = "";
            for(int letter : temp) letters+=(to_string(letter)+'.');
            if(map.contains(letters)) ans[map[letters]].push_back(str);
            else{
                map[letters] = ans.size();
                ans.push_back({str});
            }
        }

        return ans;
    }
};
