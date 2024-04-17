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
    
    vector<string> search(TrieNode* root,string str) {
        TrieNode* node=root;
        vector<string> v;
        for(int j=0;j<str.size();j++){
            if(!node->children[str[j]-'a']){
                return {"0"};
            }
            node=node->children[str[j]-'a'];
           
            
        }
            for(auto w:node->prefix){
                v.push_back(w);
            }
            
        return v;
    }
   
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {   TrieNode* root=new TrieNode();
        for(int i=0;i<n;i++){
            insert(root,contact[i]);
        }
        vector<vector<string>> ans;
        string str="";
        for(int i=0;i<s.size();i++){
            str+=s[i];
            vector<string> a=search(root,str);
            sort(a.begin(),a.end());
            ans.push_back(a);
        }
        return ans;
    }
    int main(){
        int n;
        cout<<"enter no of contacts:\n";
        cin>>n;
        string contact[n];
        for(int i=0;i<n;i++){
            cin>>contact[i];
        }
        string s;
        cout<<"enter string:\n";
        cin>>s;
        vector<vector<string>> ans=displayContacts(n,contact,s);
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans.size();j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
        return 0;
    }