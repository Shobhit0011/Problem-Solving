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
    bool isonechild(TreeNode* root) {
        if(root==NULL)return 1;
        if(root->left==NULL && root->right==nullptr)return 1;
        if(root->left && root->right)return 0;

        return isonechild(root->left)&& isonechild(root->right);
    }
      int main(){
        TreeNode* root1=new TreeNode(15);
    root1->left=new TreeNode(5);
    root1->left->right=new TreeNode(13);
    root1->left->right->right=new TreeNode(14);
    root1->left->right->left=new TreeNode(8);
    root1->left->right->left->right=new TreeNode(10);
    bool ans=isonechild(root1);
    if(ans){
        cout<<"TREE HAS ONLY ONE CHILD AT EACH NODE";
    }
    else{
        cout<<"NO!!! TREE HAS TWO CHILD";
    }
    return 0;
 }