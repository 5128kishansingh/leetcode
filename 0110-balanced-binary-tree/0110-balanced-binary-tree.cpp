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
    int height(TreeNode* root){
        if(root==0)return 0;

        int left=1+height(root->left);
        int right=1+height(root->right);
        return  max(left,right);
    }
   void inorder(TreeNode* root,int &ans){
        if(root==NULL)return ;

        inorder(root->left,ans);

        int left=1+height(root->left);
        int right=1+height(root->right);
        if(abs(left-right)>1)ans=false;
        
        inorder(root->right,ans);
    }
    bool isBalanced(TreeNode* root) {\
        int ans=true;
        inorder(root,ans);
        return ans;

    }
};