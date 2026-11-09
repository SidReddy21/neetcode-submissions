class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> prereqs(numCourses);
        vector<vector<int>> courses(numCourses);
        for(auto& pre : prerequisites){
            prereqs[pre[0]]++;
            courses[pre[1]].push_back(pre[0]);
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++) if(prereqs[i] == 0) q.push(i);

        int count = 0;
        vector<int> ans;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            count++;
            ans.push_back(course);
            for(int key : courses[course]){
                prereqs[key]--;
                if(prereqs[key] == 0) q.push(key);
            }
        }

        return count == numCourses ? ans : vector<int>{};
    }
};
