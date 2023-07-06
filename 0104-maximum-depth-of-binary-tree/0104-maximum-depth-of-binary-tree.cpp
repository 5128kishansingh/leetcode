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
    
    int f(TreeNode* root){
        if(root==0)return 0;

        int left=1+f(root->left);
        int right=1+f(root->right);
        return max(left,right);
    }
    int maxDepth(TreeNode* root) {
        
        int res=f(root);
        return res;
    }
};