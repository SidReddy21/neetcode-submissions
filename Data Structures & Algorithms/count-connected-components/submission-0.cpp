class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> seen(n,0);
        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int count = 0;
        for(int i = 0; i < n; i++){
            if(!seen[i]){
                bfs(adj,seen,i);
                count++;
            }
        }

        return count;
    }

    void bfs(vector<vector<int>>& adj, vector<bool>& seen, int node){
        queue<int> q;
        q.push({node});
        while(!q.empty()){
            int n = q.front();
            q.pop();
            seen[n] = true;
            for(int nei : adj[n]){
                if(seen[nei]) continue;
                q.push(nei);
            }
        }
    }
};
