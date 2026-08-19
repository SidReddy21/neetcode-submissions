class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> letters(300,0);
        int left = 0,right = 0,MAX = 0;


        while(right < s.size()){
            if(letters[s[right]]){
                while(s[left] != s[right]) letters[s[left++]] = 0;
                letters[s[left++]] = 0;
            }else letters[s[right++]] = 1;
            MAX = max(MAX,right-left);
        }

        return MAX;

    }
};
