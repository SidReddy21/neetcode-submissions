class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> visit = {-1};
        queue<pair<int,int>> q;
        q.push({0,-1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(int nei : adj[node]){
                if(nei == parent) continue;
                if(visit.contains(nei)) return false;
                visit.insert(nei);
                q.push({nei,node});
            }
        }

        return visit.size() == n;
    }
};
