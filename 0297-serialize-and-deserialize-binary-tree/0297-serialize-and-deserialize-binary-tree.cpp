/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    int extractVal(string &s)
    {
        stringstream ss(s);
        string str;
        while(getline(ss,str,'_'))
        {
            return stoi(str);
        }
        return 0; 
    }
    string getAddressAsString(const TreeNode* node) {
        ostringstream oss;
        oss << static_cast<const void*>(node);
        return oss.str();
    }
    void inorder(TreeNode *root,string &serialstr)
    {
        if(root==NULL) return;
        inorder(root->left,serialstr);
        serialstr+=((to_string(root->val)+"_"+getAddressAsString(root))+" ");
        inorder(root->right,serialstr);
    }
    void preorder(TreeNode *root,string &serialstr)
    {
        if(root==NULL) return;
        serialstr+=((to_string(root->val)+"_"+getAddressAsString(root))+" ");
        preorder(root->left,serialstr);
        preorder(root->right,serialstr);
    }
    
    TreeNode* genTree(int in_s,int in_e,int pre_s,int pre_e,vector<string> &inorder,vector<string> &preorder)
    {
       
        if(in_s>in_e) return NULL;
        
        TreeNode *root=new TreeNode(extractVal(preorder[pre_s]));
        int idx;
        for(int i=in_s;i<=in_e;i++)
        {
            if(inorder[i]==preorder[pre_s])
            {
                idx=i;break;
            }
        }
        int leftsize=idx-in_s;
        int rightsize=in_e-idx;
        
        root->left=genTree(in_s,idx-1,pre_s+1,pre_s+leftsize,inorder,preorder);
        root->right=genTree(idx+1,in_e,pre_s+leftsize+1,pre_e,inorder,preorder);
        return root;
    }
    
    string serialize(TreeNode* root) {
        
        string serialstr;
        inorder(root,serialstr);
        serialstr+="$ ";
        preorder(root,serialstr);
        return serialstr;
    }

    
    TreeNode* deserialize(string data) {
        stringstream ss(data); 
        string str;
        bool seperator_seen=0;
        vector<string> inorder,preorder;
        while(getline(ss,str,' '))
        {
            if(str=="$")
            {
                seperator_seen=1;
            }
            else{
                if(seperator_seen==0)
                {
                    inorder.push_back(str);
                }
                else preorder.push_back(str);
            }
        }
        
        return genTree(0,inorder.size()-1,0,preorder.size()-1,inorder,preorder);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));