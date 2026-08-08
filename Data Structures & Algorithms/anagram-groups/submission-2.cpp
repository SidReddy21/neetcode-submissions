class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,int> map;
        vector<vector<string>> ans;

        for(string s : strs){
            vector<int> count(26,0);
            for(char c : s){
                count[c-'a']++;
            }
            string temp = "";
            for(int num : count){
                temp+=to_string(num)+'.';
            }

            if(map.contains(temp)) ans[map[temp]].push_back(s);
            else{
                map[temp] = ans.size();
                ans.push_back({s});
            }
        }

        return ans;
    }
};
