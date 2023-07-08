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
   void f(TreeNode* p,TreeNode* q,bool &ans){
        if(p==NULL&&q==NULL)return ;
        
        else if(p==NULL&&q!=NULL){ans=false;return;}
        else if(p!=NULL&&q==NULL){ans=false;return;}
        else if(p->val!=q->val){ans=false;return;}

        f(p->left,q->right,ans);
        f(p->right,q->left,ans);


    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        bool ans=true;
        f(root->left,root->right,ans);

        return ans;
    }
};