 #include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

 TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return root;
        if(root==p || root==q)
            return root;
        if(p->val<root->val && q->val<root->val)
            return LCA(root->left,p,q);
        else if(p->val>root->val && q->val>root->val)
            return LCA(root->right,p,q);
        return root;
    }
    int main(){
         TreeNode* root=new TreeNode(8);
         root->left=new TreeNode(4);
         root->right=new TreeNode(11);
         root->left->left=new TreeNode(2);
         root->left->right=new TreeNode(6);
         root->right->left=new TreeNode(9);
         root->right->right=new TreeNode(16);
         TreeNode* ans=LCA(root,root->right,root->left->left);
        cout<<ans->val;
        return 0;
    }