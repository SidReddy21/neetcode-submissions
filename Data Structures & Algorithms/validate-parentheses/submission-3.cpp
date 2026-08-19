class Solution {
public:
    bool isValid(string s) {
        vector<char> stck;
        for(char c : s){
            if(c == '(' || c == '[' || c == '{') stck.push_back(c);
            else if(stck.empty()) return false;
            else if(c == ')' && stck.back() == '(') stck.pop_back();
            else if(c == ']' && stck.back() == '[') stck.pop_back();
            else if(c == '}' && stck.back() == '{') stck.pop_back();
            else return false;
        }

        return stck.empty();
    }
};
