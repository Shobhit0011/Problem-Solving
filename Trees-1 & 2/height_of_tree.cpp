
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
 int ord(TreeNode* r,int c){
    if(r==NULL)return 0;
    int x=1+max(ord(r->left,c++),ord(r->right,c++));
    return x;
 }
int heightOfBinaryTree(TreeNode* root)
{
	// Write your code here.
    return ord(root,0);
}
 int main(){
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    int maximumdepth=heightOfBinaryTree(root);
    cout<<maximumdepth<<" ";
    return 0;
 }
