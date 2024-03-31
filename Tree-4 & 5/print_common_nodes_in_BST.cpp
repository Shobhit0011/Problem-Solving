 #include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};
 void BBST(Node* r,vector<int>& arr){
        if(r==NULL)return;
        BBST(r->left,arr);
        arr.push_back(r->val);
        BBST(r->right,arr);
    }
    vector <int> findCommon(Node *root1, Node *root2)
    {
        vector<int> arr1;
        vector<int> arr2;
        BBST(root1,arr1);
        BBST(root2,arr2);
         unordered_set<int> elements(arr1.begin(), arr1.end());
         vector<int> intersection;

        for (int num : arr2) {
              if (elements.find(num) != elements.end()) {
                    intersection.push_back(num);
            
                     elements.erase(num);
        }
    }
    return intersection;
    }
    int main(){
        Node* root1=new Node(7);
    root1->left=new Node(5);
    root1->right=new Node(10);
    root1->right->left=new Node(9);
    root1->right->right=new Node(11);

    Node* root2=new Node(7);
    root2->left=new Node(5);
    root2->right=new Node(10);
    root2->right->left=new Node(9);
    root2->right->right=new Node(11);
    vector<int> ans=findCommon(root1,root2);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
 }