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
TreeNode* prevo=NULL;
TreeNode* element1=NULL;
TreeNode* element2=NULL;
void inor(TreeNode* r,vector<int>& e){
    if(r==NULL)return;
    inor(r->left,e);
    e.push_back(r->val);
    inor(r->right,e);
}
    void inorder(TreeNode* root){
        if(root==NULL)return;
        inorder(root->left);
       
        if(prevo!=NULL&&root->val<prevo->val&&element1==NULL){
                element1=prevo;
                element2=root;
            }
        else if(prevo!=NULL && root->val<prevo->val){
            element2=root;
        }
        prevo=root;
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        if(root==NULL)return ;
        inorder(root);
        int t=element1->val;
        element1->val=element2->val;
        element2->val=t;
    }
     int main(){
         TreeNode* root=new TreeNode(5);
         root->left=new TreeNode(3);
         root->right=new TreeNode(7);
         root->left->left=new TreeNode(6);
         root->left->right=new TreeNode(4);
         root->right->left=new TreeNode(2);
         root->right->right=new TreeNode(16);
         recoverTree(root);
        vector<int> ans;
        inor(root,ans);
        for(int i:ans)cout<<i<<" ";
        return 0;
    }