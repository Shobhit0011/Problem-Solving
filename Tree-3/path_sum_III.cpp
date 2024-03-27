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
    void findPaths(TreeNode* node, int targetSum, vector<int>& path, int& count) {
        if (!node) return;
        path.push_back(node->val);
        long long sum = 0;
        for (int i = path.size() - 1; i >= 0; --i) {
            sum += path[i];
            if (sum == targetSum) {
                count++;
            }
        }
        
        findPaths(node->left, targetSum, path, count);
        findPaths(node->right, targetSum, path, count);
        path.pop_back();
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        int count = 0;
        findPaths(root, targetSum, path, count);
        return count;
    }
    int main(){
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(8);
    root->right->left=new TreeNode(1);
    root->right->right=new TreeNode(7);
    int ans=pathSum(root,12);
   cout<<" "<<ans<<" ";
    return 0;
 }