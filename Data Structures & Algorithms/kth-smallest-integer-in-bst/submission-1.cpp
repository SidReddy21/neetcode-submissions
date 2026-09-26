/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return false;
        priority_queue<int> maxHeap;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                if(maxHeap.size() == k){
                    if(maxHeap.top() > q.front()->val){
                        maxHeap.pop();
                        maxHeap.push(q.front()->val);
                    }
                }else maxHeap.push(q.front()->val);

                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            cout << maxHeap.top() << endl;
        }

        return maxHeap.top();
    }
};
