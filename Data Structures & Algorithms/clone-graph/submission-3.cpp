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
        if(!node) return nullptr;
        unordered_map<Node*,Node*> map;
        dfs(node,map);

        return map[node];
    }

    void dfs(Node* node,unordered_map<Node*,Node*>& map){
        if(map.contains(node)) return;
        Node* temp = new Node(node->val);
        map[node] = temp;
        for(Node* nei : node->neighbors){
            dfs(nei,map);
            temp->neighbors.push_back(map[nei]);
        }
    }
};
