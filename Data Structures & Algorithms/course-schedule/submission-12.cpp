class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        for(auto pre : prerequisites){
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int course = q.front();
            q.pop();
            for(int nei : adj[course]){
                indegree[nei]--;
                if(indegree[nei] == 0) q.push(nei);
            }
        }

        return indegree == vector<int>(numCourses,0);
    }
};
