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
    void inorder(TreeNode* root,vector<int> &arr){
        
        if(root==NULL) return ;
        arr.push_back(root->val);
        inorder(root->left,arr);
        
        inorder(root->right,arr);
    }
    void flatten(TreeNode* root) {
        vector<int>arr;
        if(root==NULL) return;
        inorder(root,arr);
       
        int n=arr.size();
        
        TreeNode* curr=root;

        for(int i=1;i<n;i++){
            
           curr->left=NULL;
           TreeNode*temp=new TreeNode(arr[i]);
           curr->right=temp;
           curr=curr->right;
        }
        curr->right=NULL;
        curr->left=NULL;
        
    }
};