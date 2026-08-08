class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> letters(26,0);
        
        char curr = s[0];
        letters[curr-'A']++;
        int mostFreq = 1;
        int left = 0;
        int right = 1;
        int MAX = 1;
        while(right < s.size()){
            
            letters[s[right]-'A']++;
            mostFreq = max(mostFreq,letters[s[right]-'A']);

            while(right-left+1-mostFreq > k){
                letters[s[left]-'A']--;
                left++;
            }

            MAX = max(MAX,right-left+1);
            right++;
        }

        return MAX;
    }
};
