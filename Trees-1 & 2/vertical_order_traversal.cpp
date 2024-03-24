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
    void vertical(map<int, map<int, vector<int>>> &nodes, TreeNode* root, int x, int y) {
        if (root == NULL) return;
        nodes[x][y].push_back(root->val);
        vertical(nodes, root->left, x - 1, y + 1);
        vertical(nodes, root->right, x + 1, y + 1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> nodes;
        vertical(nodes, root, 0, 0);
        
        vector<vector<int>> ans;
        for (auto col : nodes) {
            vector<int> colVals;
            for (auto row : col.second) {
                sort(row.second.begin(), row.second.end());
                colVals.insert(colVals.end(), row.second.begin(), row.second.end());
            }
            ans.push_back(colVals);
        }
        return ans;
    }
    int main(){
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    
    vector<vector<int>> ans;
	ans=verticalTraversal(root);
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