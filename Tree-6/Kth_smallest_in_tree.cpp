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
int c=0;
TreeNode* inorder(TreeNode* r,int &k){
    if(r==NULL){
        return NULL;
    }
    TreeNode* left=inorder(r->left,k);
        if(!left)return left;
        c++;
        if(c==k)return r;
        return inorder(r->right,k);
     
 }
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* ans=inorder(root,k);
        return ans->val;
        
    }
     int main(){
         TreeNode* root=new TreeNode(8);
         root->left=new TreeNode(4);
         root->right=new TreeNode(11);
         root->left->left=new TreeNode(2);
         root->left->right=new TreeNode(6);
         root->right->left=new TreeNode(9);
         root->right->right=new TreeNode(16);
         int ans=kthSmallest(root,3);
        cout<<ans;
        return 0;
    }