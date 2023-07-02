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
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>>ans;
        vector<int>res;
        if(root==NULL)return res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>v;
            int n=q.size();
            for(int  i=0;i<n;i++){
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left!=NULL)q.push(temp->left);
            if(temp->right!=NULL)q.push(temp->right);
            v.push_back(temp->val);
            }
            ans.push_back(v);
        }
        int n=ans.size();
        
        for(int i=0;i<n;i++){
            int m=ans[i].size();
            res.push_back(ans[i][m-1]);
        }
        return  res;
    }
};