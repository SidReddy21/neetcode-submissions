class Solution {
public:

    string minWindow(string s, string t) {

        if(t.size() > s.size() || t.empty()) return "";

        unordered_map<char,int> mapT;
        unordered_map<char,int> mapS;
        
        for(char c : t){
            mapT[c]++;
        }

        int left = 0;
        int right = 0;
        int need = mapT.size();
        int have = 0;
        string MIN = s;

        while(right < s.size()){

            if(mapT.contains(s[right])){
                mapS[s[right]]++;
                if(mapS[s[right]] == mapT[s[right]]) have++;
            }
            while(need == have){
                if(MIN.size() > right-left+1) MIN = s.substr(left,right-left+1);
                if(mapT.contains(s[left]) == 0){
                    left++;
                    continue;
                }
                mapS[s[left]]--;
                if(mapS[s[left]] >= mapT[s[left]]){
                    left++;
                    continue;
                }else{
                    mapS[s[left]]++;
                    break;
                }
            }


            /*
            if it exists in mapT add it to mapS
            as soon as a mapS has at least as many as mapT start moving the left pointer up
                check fi the value your removing would be contained in T, and if it is we want ot make sure 
                if we remove it that the amount in mapS woudl still be greater than the amountin mapT



            */


            right++;
        }

        // if(checkMap(mapT,mapS) == false) return "";
        if(need != have) return "";
    
        return MIN;
    }
};
