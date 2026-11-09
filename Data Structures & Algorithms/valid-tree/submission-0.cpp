class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> nodes(n);
        vector<bool> seen(n,0);
        for(auto& edge : edges){
            nodes[edge[0]].push_back(edge[1]);
            nodes[edge[1]].push_back(edge[0]);
        }
        queue<pair<int,int>> q;
        q.push({0,-1});
        seen[0] = true;
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(int nei : nodes[node]){
                if(nei == parent) continue;
                if(seen[nei]) return false;
                seen[nei] = true;
                q.push({nei,node});
            }
        }
        return seen == vector<bool>(n,1);        
    }
};
