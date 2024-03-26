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
 
 void dfs(TreeNode* node, string path, vector<string>& paths) {
        path +=to_string(node->val);
        if (!node->left && !node->right) { 
            paths.push_back(path); 
        } 
        else {
            if (node->left) dfs(node->left, path + "->", paths);
            if (node->right) dfs(node->right, path + "->", paths);
        }
    }
vector<string> binaryTreePaths(TreeNode* root) {
     vector<string> paths;
        if (root) dfs(root, "", paths);
        return paths;
    }
  int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->right->right=new TreeNode(5);
    
    vector<string> ans;
	ans=binaryTreePaths(root);
	cout<<"[";
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<",";
	}
	cout<<"]";
    return 0;
 }