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
   void path(TreeNode* r,vector<int>& sum,int t){
           t+=r->val;
          if(r->left==NULL && r->right==NULL){
            sum.push_back(t);
            t=0;
            return;
          }
         
          if(r->left)path(r->left,sum,t);
          if(r->right)path(r->right,sum,t);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return 0;
        vector<int> sum;
        path(root,sum,0);
        for(int i=0;i<sum.size();i++){
            if(targetSum==sum[i])return 1;
        }
        return 0;
    }
     int main(){
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    
    bool a=(root,30);
    if(a)cout<<"YES";
    else{
        cout<<"NO";
    }
    return 0;
 }