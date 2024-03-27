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
bool paths(TreeNode* A,int B,vector<int> &ans){
     if(A==NULL)return 0;
     ans.push_back(A->val);
     if(A->val==B || paths(A->left,B,ans) || paths(A->right,B,ans)){
         return 1;
     }
     ans.pop_back();
     return 0;
 }
vector<int> solve(TreeNode* A, int B) {
    vector<int> ans;
    paths(A,B,ans);
    return ans;
}
int main(){
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    
    vector<int> answer;
    answer=solve(root,15);
    for(int i:answer){
        cout<<i<<" ";
    }
    return 0;
 }