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
int sumfind(TreeNode* root,int &min,int &max,bool &is_bst,int &max_sum)
    {
        if(!root){
            is_bst=1;
            return 0;
        }
        int tmp=INT_MAX; 
        bool left_bst=false,right_bst=false; 
        max=INT_MIN; 
        int left_sum=0;
        left_sum+=sumfind(root->left,min,max,is_bst,max_sum);
     
        if(is_bst && root->val > max)  
           left_bst=true;
        tmp=min;
        min=INT_MAX;
        int right_sum=0;
        right_sum+=sumfind(root->right,min,max,is_bst,max_sum);
      
        if(is_bst && root->val < min)
          right_bst=true;
           
        if(tmp<min)
          min=tmp;
        if(root->val <min)
          min=root->val;
        if(root->val > max)
          max = root->val;
        if(left_bst && right_bst)
        {
            if(left_sum + right_sum + root->val > max_sum)
               max_sum=left_sum + right_sum + root->val ;
           return left_sum + right_sum + root->val ; 
        }
        else{
            is_bst=0;
            return 0;
        }
    }
    int maxSumBST(TreeNode* root) {
        int min=INT_MAX;
        int max=INT_MIN;
        bool is_bst=0;
        int max_sum=0;
        sumfind(root,min,max,is_bst,max_sum);
        return max_sum;
    }
     int main(){
    //tree............
    TreeNode* root=new TreeNode(8);
    root->left=new TreeNode(6);
    root->right=new TreeNode(11);
    root->right->left=new TreeNode(10);
    root->right->right=new TreeNode(12);
    root->left->left=new TreeNode(6);
    root->left->right=new TreeNode(9);
    int ans=maxSumBST(root);
    cout<<ans<<" ";
    return 0;
 }