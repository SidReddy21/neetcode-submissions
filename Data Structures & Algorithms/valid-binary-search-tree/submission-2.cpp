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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return helper(root->left,INT_MIN,root->val) && helper(root->right,root->val,INT_MAX);
    }

    bool helper(TreeNode* root, int MIN, int MAX){
        if(!root) return true;
        else if(root->val > MIN && root->val < MAX) return helper(root->left,MIN,min(MAX,root->val)) && helper(root->right,max(MIN,root->val),MAX);
        else return false;
    }
};
