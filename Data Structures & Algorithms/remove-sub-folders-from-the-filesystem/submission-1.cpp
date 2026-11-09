class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        unordered_set<string> set;
        vector<string> ans;
        for(string& str : folder){
            int i = str.find('/',1);
            while(i <= str.size() && !set.contains(str.substr(0,i))){
                i = str.find('/',i+1);
            }
            if(i > str.size()) ans.push_back(str);
            set.insert(str);
        }

        return ans;
    }
};