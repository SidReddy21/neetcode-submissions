class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> prereqs(numCourses,0);
        unordered_map<int,vector<int>> map;
        for(vector<int> pre : prerequisites){
            prereqs[pre[0]]++;
            map[pre[1]].push_back(pre[0]);
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++) if(prereqs[i] == 0) q.push(i);

        int count = 0;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            count++;
            for(int nei : map[course]){
                prereqs[nei]--;
                if(prereqs[nei] == 0) q.push(nei);
            }

        }

        return count == numCourses;
    }

    

    
};
