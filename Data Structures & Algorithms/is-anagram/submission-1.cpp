class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> letters(26,0);
        for(char c : s) letters[c-'a']++;
        for(char c : t) letters[c-'a']--;

        for(int letter : letters) if(letter != 0) return false;

        return true;
    }
};
