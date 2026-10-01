/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> map;
        return dfs(node,map);
    }

    Node* dfs(Node* node, unordered_map<Node*,Node*>& oldToNew){
        if(!node) return nullptr;
        if(oldToNew.contains(node)) return oldToNew[node];

        Node* copy = new Node(node->val);
        oldToNew[node] = copy;

        for(auto n : node->neighbors){
            
            dfs(n,oldToNew);
            copy->neighbors.push_back(oldToNew[n]);
        }

        return copy;
    }
};
