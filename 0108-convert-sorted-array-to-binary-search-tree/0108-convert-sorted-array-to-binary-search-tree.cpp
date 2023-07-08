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
    TreeNode* f(vector<int>&nums,int low,int high){

        if(low>high)return NULL;
        int mid=(low+high)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        TreeNode* lef=f(nums,low,mid-1);
        TreeNode* righ=f(nums,mid+1,high);
        root->left=lef;
        root->right=righ;
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();

        return f(nums,0,n-1);
    }
};