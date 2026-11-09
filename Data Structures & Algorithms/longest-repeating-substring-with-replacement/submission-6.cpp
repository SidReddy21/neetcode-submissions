class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        unordered_map<char,int> map;
        int MAX = 0;
        int ans = 0;
        while(right < s.size()){
            MAX = max(MAX,++map[s[right]]);

            while((right-left+1-k-MAX > 0)){
                map[s[left++]]--;
            }

            ans = max(ans,right-left+1);
            right++;

        }

        return ans;
            //add the chrACTER TO THE map
            //max  = max(MAX, map[character])

            // while left <right right-left+1-k > 0
                // map[s[left]]--
                // left++;
            
            // ans = max(ans,right-left+1)

    }
};
