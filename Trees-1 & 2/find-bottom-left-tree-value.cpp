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
 void pre(map<int,vector<int>> &ans,TreeNode* r,int c,int &mx){
        if(r==NULL)return;
        ans[c].push_back(r->val);
        mx=max(mx,c);
        pre(ans,r->left,c+1,mx);
        pre(ans,r->right,c+1,mx);
    }
    int findBottomLeftValue(TreeNode* root) {
        map<int,vector<int>> ans;
        int mx=0;
        pre(ans,root,0,mx);
        return ans[mx][0];
    }
     int main(){
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    
    
	int ans=findBottomLeftValue(root);
	
	cout<<ans;
    return 0;
 }