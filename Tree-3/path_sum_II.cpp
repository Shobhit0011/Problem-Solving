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
    void paths(TreeNode* r,vector<vector<int>>& ans,vector<int> t,int tsum){
         t.push_back(r->val);
         if(r->left==NULL&& r->right==NULL){
            if(accumulate(t.begin(),t.end(),0)==tsum)
               ans.push_back(t);
            t.clear();
            return;
         }
         if(r->left)paths(r->left,ans,t,tsum);
         if(r->right)paths(r->right,ans,t,tsum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root==NULL)return ans;
        vector<int> t;
        paths(root,ans,t,targetSum);
        return ans;
    }
    int main(){
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(8);
    root->right->left=new TreeNode(1);
    root->right->right=new TreeNode(7);
    
    vector<vector<int>> ans;
    ans=pathSum(root,12);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    return 0;
 }