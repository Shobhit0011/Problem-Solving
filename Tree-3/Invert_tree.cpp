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
    void printi(TreeNode* r){
        if(r==NULL)return;
        printi(r->left);
        cout<<" "<<r->val<<" ";
        printi(r->right);
    }
    void invert(TreeNode* node) {
        if(node == nullptr) return;
        swap(node->left, node->right);
        invert(node->left);
        invert(node->right);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
    int main(){
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    
    TreeNode* r=invertTree(root);
    printi(r);
    return 0;
 }
