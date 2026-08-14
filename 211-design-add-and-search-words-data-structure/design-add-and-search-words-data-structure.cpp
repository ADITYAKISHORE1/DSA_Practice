class TrieNode{
public:
    TrieNode* child[26];
    bool isEnd;
    TrieNode(){
        isEnd=false;
        for(int i=0;i<26;i++) child[i]=nullptr;
    }
};
class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root=new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* ptr=root;
        for(auto& c:word){
            if(ptr->child[c-'a']==nullptr){
                ptr->child[c-'a']=new TrieNode();
            }
            ptr=ptr->child[c-'a'];
        }
        ptr->isEnd=true;
    }
    
    bool search(string word) {
        return src(word,root);
    }
    bool src(string word,TrieNode* r){
        TrieNode* ptr=r;
        for(int c=0;c<word.size();c++){
            if(word[c]=='.'){
                bool b=false;
                for(int i=0;i<26;i++){
                    if(ptr->child[i]!=nullptr){
                        string s=word.substr(c+1);
                        b|=src(s,ptr->child[i]);
                    }
                }
                return b;
            }else{
                if(ptr->child[word[c]-'a']==nullptr) return false;
                ptr=ptr->child[word[c]-'a'];
            }
        }
        return ptr->isEnd;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */