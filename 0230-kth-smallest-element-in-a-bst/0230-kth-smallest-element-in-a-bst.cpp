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
    void insert(TreeNode* root,stack<int> &s){
        if(root==NULL)return;
        insert(root->right,s);
        s.push(root->val);
        insert(root->left,s);
    }
    int kthSmallest(TreeNode* root, int k) {
      stack<int> s;
      insert(root,s);
      for(int i=1;i<k;i++)
      s.pop();
      return s.top();  
    }
};