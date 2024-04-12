#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    bool isEnd=0;
    vector<string> prefix;
    TrieNode* children[26];
     TrieNode() {
        for (auto &a : children) a = NULL;
    }
};
    void insert(TrieNode* root,string word) {
        TrieNode* node=root;
        for(char &i:word){
            if(!node->children[i-'a']){
                node->children[i-'a']=new TrieNode();
            }
            node=node->children[i-'a'];
            node->prefix.push_back(word);
        }
        node->isEnd=1;
    }
    
    bool search(TrieNode* root) {
        TrieNode* node=root;
        while(1){
            char c;
            cin>>c;
            if(c=='*')break;
            if(!node->children[c-'a']){
                cout<<"Oo! No words found"<<"\n";
                return 0;
            }
            node=node->children[c-'a'];
            for(auto w:node->prefix){
                cout<<w<<" ";
            }
            cout<<"\n";
        }
        if(node->isEnd) return 1;
        return 0;
    }
   
int main(){
    TrieNode* root=new TrieNode();
    insert(root,"hello");
    insert(root,"dog");
    insert(root,"hell");
    insert(root,"cat");
    insert(root,"a");
    insert(root,"hel");
    insert(root,"help");
    insert(root,"helps");
    insert(root,"helping");
    bool s=search(root);
    return 0;
}
