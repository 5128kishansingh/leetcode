/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
       if(root==NULL)return root;

        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<Node*>v;
            for(int i=0;i<n;i++){
                Node* temp=q.front();
                q.pop();
                v.push_back(temp);
                if(temp->left!=NULL)
                q.push(temp->left);
                if(temp->right!=NULL)
                q.push(temp->right);

            }
            int m=v.size();
            for(int i=0;i<m-1;i++)
            v[i]->next=v[i+1];
            v[m-1]->next=NULL;
        }
        return root;
    }
};