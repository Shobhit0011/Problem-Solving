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
void leafNode(TreeNode* root,vector<int>& ans)
{
    if (root == NULL)
        return;
    leafNode(root->left,ans);
    if (!(root->left) && !(root->right))
        ans.push_back(root->val);
 
    leafNode(root->right,ans);
}
 
void left(TreeNode* root,vector<int>& ans)
{
    if (root == NULL)
        return;
 
    if (root->left) {
        ans.push_back(root->val);
        left(root->left,ans);
    }
    else if (root->right) {
        ans.push_back(root->val);
        left(root->right,ans);
    }
}
void right(TreeNode* root,vector<int>& ans)
{
    if (root == NULL)
        return;
 
    if (root->right) {
        right(root->right,ans);
        ans.push_back(root->val);
    }
    else if (root->left) {
        right(root->left,ans);
         ans.push_back(root->val);
    }
}
 
vector<int> traverseBoundary(TreeNode *root)
{
	// Write your code here.
    vector<int> ans;
    if (root == NULL)
        return ans;
     ans.push_back(root->val);
    left(root->left,ans);
    leafNode(root->left,ans);
    leafNode(root->right,ans);
    right(root->right,ans);
    return ans;
}
 int main(){
    //tree............
    TreeNode* root=new TreeNode(8);
    root->left=new TreeNode(6);
    root->right=new TreeNode(11);
    root->right->left=new TreeNode(10);
    root->right->right=new TreeNode(12);
   vector<int> ans=traverseBoundary(root);
   
    //printing boundary ...........
   for(auto i:ans){
    cout<<i<<" ";
   }
    return 0;
 }
