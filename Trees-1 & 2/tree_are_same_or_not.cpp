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
 void inorder(TreeNode* p,string &a){
        if(p==NULL){
            a.push_back('&');
            return;
        }
        inorder(p->left,a);
         a.push_back(p->val);
        inorder(p->right,a);
    }
    void preorder(TreeNode* p,string &a){
        if(p==NULL){
            a.push_back('&');
            return;
        }
        a.push_back(p->val);
        preorder(p->left,a);
        preorder(p->right,a);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        string a,b,c,d;
        preorder(p,a);
        preorder(q,b);
        inorder(p,c);
        inorder(q,d);
        if(a==b && c==d){
            return 1;
        }
        return 0;
    }
    int main(){
        // first tree
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
        //second tree
    TreeNode* root1=new TreeNode(3);
    root1->left=new TreeNode(9);
    root1->right=new TreeNode(20);
    root1->right->left=new TreeNode(15);
    root1->right->right=new TreeNode(7);

    bool ans=isSameTree(root,root1);
    if(ans==1){
        cout<<"SAME TREE";
    }else{
        cout<<"NOT SAME TREE";
    }
    return 0;
 }
