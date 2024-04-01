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

void inor(TreeNode* r,vector<int>& e){
    if(r==NULL)return;
    inor(r->left,e);
    e.push_back(r->val);
    inor(r->right,e);
}
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)return 0;
        if(root->left==NULL && root->right==NULL)return 0;
        vector<int> e;
        inor(root,e);
        for(int i=0;i<e.size();i++){
            if(find(e.begin()+i+1,e.end(),k-e[i])!=e.end() ){
                return 1;
            }
        }
        return 0;
    }
    int main(){
         TreeNode* root=new TreeNode(8);
         root->left=new TreeNode(4);
         root->right=new TreeNode(11);
         root->left->left=new TreeNode(2);
         root->left->right=new TreeNode(6);
         root->right->left=new TreeNode(9);
         root->right->right=new TreeNode(16);
         bool ans=findTarget(root,13);
        if(ans){
            cout<<"TWO SUM IS PRESENT";
        }
        else{
            cout<<"NOT PRESENT";
        }
        return 0;
    }
