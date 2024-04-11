#include<bits/stdc++.h>
using namespace std;
class TrieNode{
public:
    TrieNode *child[26];
    bool isEnd;
    
    TrieNode(){
        isEnd = false;
        for (auto &a : child) a = NULL;
    }
};
    TrieNode* newNode ;
    string check(string word){
        TrieNode *t = newNode;
        string s = "";
        
        for(auto i : word){
            if(!t->child[i-'a']) break;
            s += i;
            t = t->child[i-'a'];
            if(t->isEnd) return s;
        }
        return word;
    }
    
    void insert(string word){
        TrieNode *temp = newNode;
        
        for(auto l : word){
            if(!temp->child[l-'a']) 
                temp->child[l-'a'] = new TrieNode();
            temp = temp->child[l-'a'];
        }
        
        temp->isEnd = true;
    }
    
    string replaceWords(vector<string>& dict, string sentence) {
        newNode = new TrieNode();
        for(auto s : dict) 
            insert(s);
       istringstream ss(sentence);//using istringstream to extract words from sentence 
        string word = "", ans="";
        
        for(; ss>>word; ){
            ans += check(word);
            ans += ' ';
        }
        ans.pop_back();
        
        return ans;
    }
    int main(){
        vector<string> dict={"cat","bat","rat"};
        string sentence="the cattle was rattled by the battery";
        string ans=replaceWords(dict,sentence);
        cout<<ans;
    }