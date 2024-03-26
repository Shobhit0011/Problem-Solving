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
    bool path(TreeNode* node, int value, string& ans) {
        if (!node) return false;
        if (node->val == value) return true;

        if (node->left && path(node->left, value, ans)) {
            ans.push_back('L');
            return true;
        }
        if (node->right && path(node->right, value, ans)) {
            ans.push_back('R');
            return true;
        }
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string pathToStart, pathToDest;
        path(root, startValue, pathToStart);
        path(root, destValue, pathToDest);
        reverse(pathToStart.begin(), pathToStart.end());
        reverse(pathToDest.begin(), pathToDest.end());

        int common = 0;
        while (common < pathToStart.size() && common < pathToDest.size() &&
               pathToStart[common] == pathToDest[common]) {
            common++;
        }

        string ans;
        ans.append(pathToStart.size() - common, 'U');
        ans.append(pathToDest.begin() + common, pathToDest.end());
        return ans;
    }
int main(){
    TreeNode* root=new TreeNode(3);                              
    root->left=new TreeNode(9);                               
    root->right=new TreeNode(20);                           
    
    root->left->left=new TreeNode(17);
    root->left->right=new TreeNode(10);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    string answer;
    answer=getDirections(root,10,7);
    cout<<answer;
    return 0;
 }
