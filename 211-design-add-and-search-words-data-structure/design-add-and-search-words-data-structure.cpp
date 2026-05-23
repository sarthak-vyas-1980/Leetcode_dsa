class TrieNode {
public:
    char val;
    bool isTerminal;
    TrieNode* next[26];
    TrieNode(char data){
        val = data;
        isTerminal = false;
        for(int i=0; i<26; i++){
            this->next[i] = NULL;
        }
    }
};
class Trie {
public:
    TrieNode* root;
    Trie (char data){
        root = new TrieNode(data);
    }
    void addWord(string word, TrieNode* root){
        if(word.length()==0){
            root->isTerminal = true;
            return ;
        }
        int index = word[0] - 'a';
        TrieNode* temp = root->next[index];
        if(!temp){
            root->next[index] = new TrieNode(word[0]);
            addWord(word.substr(1, word.length()-1), root->next[index]);
        }
        else addWord(word.substr(1, word.length()-1), temp);
    }
    bool checkWord(string word, TrieNode* root){
        if(word.length()==0) return root->isTerminal;

        if(word[0] == '.'){
            for(int i=0; i<26; i++){
                if(root->next[i] != NULL){
                    bool temp = checkWord(word.substr(1), root->next[i]);
                    if(temp) return true;
                }
            }
            return false;
        }
        else{
            int index = word[0] - 'a';
            TrieNode* temp = root->next[index];

            if(!temp) return false;
            else return checkWord(word.substr(1, word.length()-1), temp);
        }
    }
};

class WordDictionary {
    Trie* trie;
public:
    WordDictionary() {
        trie = new Trie('\0');
    }
    
    void addWord(string word) {
        trie->addWord(word, trie->root);
    }
    
    bool search(string word) {
        return trie->checkWord(word, trie->root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */