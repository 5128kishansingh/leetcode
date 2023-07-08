/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)return NULL;
        int k=root->val;
        if(k<p->val&&k<q->val)
        return lowestCommonAncestor(root->right,p,q);
        if(k>p->val&&k>q->val)
        return lowestCommonAncestor(root->left,p,q);
        
        return root;
    }
};