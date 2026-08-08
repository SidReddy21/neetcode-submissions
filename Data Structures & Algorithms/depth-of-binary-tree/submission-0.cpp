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

private:

    int MAX = 0;

public:

    void bfs(TreeNode* root, int depth){
        MAX = max(MAX,depth);
        if(root->left) bfs(root->left,depth+1);
        if(root->right) bfs(root->right,depth+1);
    }

    int maxDepth(TreeNode* root) {
        if(!root) return 0;

        bfs(root,1);

        return MAX;
    }
};
