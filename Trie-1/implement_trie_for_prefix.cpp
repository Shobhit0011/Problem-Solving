#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    bool isEnd=0;
    TrieNode* children[26];
     TrieNode() {
        for (auto &a : children) a = NULL;
    }
};
    void insert(string word,TrieNode* root) {
        TrieNode* node=root;
        for(char &i:word){
            if(!node->children[i-'a']){
                node->children[i-'a']=new TrieNode();
            }
            node=node->children[i-'a'];
        }
        node->isEnd=1;
    }
    
    bool search(string word,TrieNode* root) {
        TrieNode* node=root;
        for(char &c:word){
            if(!node->children[c-'a']){
                return 0;
            }
            node=node->children[c-'a'];
        }
        if(node->isEnd)return 1;
        return 0;
    }
    
    bool startsWith(string prefix,TrieNode* root) {
        TrieNode* node=root;
        for(char &c:prefix){
            if(!node->children[c-'a']){
                return 0;
            }
            node=node->children[c-'a'];
        }
        return 1;
    }
int main(){
        vector<string> words={"apple","apple","app","app","app","app"};
        TrieNode* root=new TrieNode();
        cout<<"Trie created\n";
        insert("apple",root);
        cout<<"Inserted"<<"\n";
        if(search("apple",root))cout<<"TRUE"<<"\n";
        else cout<<"FALSE\n";
        if(startsWith("app",root))cout<<"TRUE"<<"\n";
        else cout<<"FALSE\n";
        if(search("aman",root))cout<<"TRUE"<<"\n";
        else cout<<"FALSE\n";
        insert("indian",root);
        cout<<"Inserted"<<"\n";
        if(search("india",root))cout<<"TRUE"<<"\n";
        else cout<<"FALSE\n";
    return 0;
}
