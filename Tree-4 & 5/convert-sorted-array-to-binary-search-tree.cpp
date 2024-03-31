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
TreeNode* BBST(vector<int> n,int i,int j){
    if(i>j)return NULL;
    int m=(i+j)/2;
    TreeNode* root=new TreeNode(n[m]);
    root->left=BBST(n,i,m-1);
    root->right=BBST(n,m+1,j);
    return root;

}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
         
         return BBST(nums,0,nums.size()-1);
    }
    void print(TreeNode* r){
        if(r==NULL)return;
        print(r->left);
        cout<<" "<<r->val<<" ";
        print(r->right);
    }
int main(){
    vector<int> nums={1,2,3,4,5,6,7,8,9};
    TreeNode* r=sortedArrayToBST(nums);
    print(r);
    return 0;
 }