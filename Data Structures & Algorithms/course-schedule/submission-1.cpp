class Solution {
public:

    unordered_map<int,vector<int>> map;
    unordered_set<int> set;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0; i < numCourses; i++){
            map[i] = {};
        }
        for(vector<int> pre : prerequisites){
            map[pre[1]].push_back(pre[0]);
        }
        for(int i = 0; i < numCourses; i++){
            if(!dfs(i)) return false;
        }
        return true;
    }

    bool dfs(int c){
        if(set.contains(c)) return false;
        if(map[c].empty()) return true;
        set.insert(c);
        for(int course : map[c]){
            if(!dfs(course)) return false;
        }
        set.erase(c);
        map[c].clear();
        return true;
    }
};
