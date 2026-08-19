class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> letters;
        int left = 0,right = 0,MAX = 0;


        while(right < s.size()){
            if(letters.contains(s[right])){
                while(s[left] != s[right]) letters.erase(s[left++]);
                letters.erase(s[left++]);
            }else letters.insert(s[right++]);
            MAX = max(MAX,right-left);
        }

        return MAX;

    }
};
