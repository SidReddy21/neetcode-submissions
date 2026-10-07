class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> letters(26,0);
        for(char c : words[0]) letters[c-'a']++;
        for(string& word : words){
            vector<int> temp(26,0);
            for(char c : word){
                temp[c-'a']++;
            }
            for(int i = 0; i < 26; i++) letters[i] = min(letters[i],temp[i]);
        }

        vector<string> ans;
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < letters[i]; j++){
                ans.push_back(string(1,(i+'a')));
            }
        }

        return ans;
    }
};