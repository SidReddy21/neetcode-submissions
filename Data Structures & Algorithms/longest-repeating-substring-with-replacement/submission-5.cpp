class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        int MAX = 0;
        int ans = 0;
        vector<int> letters(26,0);
        while(right < s.size()){
            letters[s[right]-'A']++;
            MAX = max(MAX,letters[s[right]-'A']);

            while(right-left+1-k-MAX > 0){
                letters[s[left++]-'A']--;
            }

            ans = max(ans,right-left+1);
            right++;
        }

        return ans;
    }
};
