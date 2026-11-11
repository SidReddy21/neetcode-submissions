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
        Node* a = new Node(node->val);
        map[node] = a;
        queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            for(Node* nei : temp->neighbors){
                if(map.contains(nei)) map[temp]->neighbors.push_back(map[nei]);
                else{
                    Node* clone = new Node(nei->val);
                    map[nei] = clone;
                    map[temp]->neighbors.push_back(map[nei]);
                    q.push(nei);
                }
            }
        }

        return map[node];
    }
};
