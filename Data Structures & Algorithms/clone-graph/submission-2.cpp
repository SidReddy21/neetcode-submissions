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
        return dfs(node,map);
    }

    Node* dfs(Node* node, unordered_map<Node*,Node*>& map){
        if(!node) return nullptr;
        if(map.contains(node)) return map[node];

        Node* temp = new Node(node->val);
        map[node] = temp;
        for(Node* nei : node->neighbors){
            temp->neighbors.push_back(dfs(nei,map));
        }

        return temp;
    }
};
