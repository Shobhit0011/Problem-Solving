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
    void pre(map<int,vector<int>> &ans,TreeNode* r,int c){
        if(r==NULL)return;
        ans[c].push_back(r->val);
        pre(ans,r->left,c+1);
        pre(ans,r->right,c+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        map<int,vector<int>> ans;
        pre(ans,root,0);
        vector<vector<int>> hu;
        for(auto i:ans){
            hu.push_back(i.second);
        }
        return hu;
    }
	int main(){
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    
    vector<vector<int>> ans;
	ans=levelOrder(root);
	cout<<"[";
	for(int i=0;i<ans.size();i++){
		cout<<"[";
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<"]";
	}
	cout<<"]";
    return 0;
 }