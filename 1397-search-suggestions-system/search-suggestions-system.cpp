class TrieNode {
public:
    char val;
    TrieNode* next[26];
    bool isTerminal;

    TrieNode(char val){
        this->val = val;
        isTerminal = false;
        for(int i=0; i<26; i++){
            next[i] = NULL;
        }
    }
};

class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
    }

    void insert(TrieNode* root, string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* next = NULL;
        if(root->next[index]){
            next = root->next[index];
        }
        else{
            next = new TrieNode(word[0]);
            root->next[index] = next;
        }
        insert(next, word.substr(1));
    }

    void search(TrieNode* root, string word, vector<vector<string>>& ans, string& path){
        if(word.length() == 0) return;

        int index = word[0] - 'a';
        if(!root->next[index]){
            for(int i=0; i<word.length(); i++){
                ans.push_back({});
            }
            return;
        }

        path.push_back(word[0]);
        vector<string> temp;
        print(root->next[index], temp, path);
        ans.push_back(temp);

        search(root->next[index], word.substr(1), ans, path);
    }

    void print(TrieNode* root, vector<string>& temp, string& path){
        if(!root || temp.size() >= 3) return;
        if(root->isTerminal) temp.push_back(path);
        if(temp.size() == 3) return;
        
        for(int i=0; i<26; i++){
            if(root->next[i]){
                path.push_back(i + 'a');
                print(root->next[i], temp, path);
                path.pop_back();
            }
        }
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        string path;
        Trie* start = new Trie();

        for(int i=0; i<products.size(); i++){
            start->insert(start->root, products[i]);
        }

        start->search(start->root, searchWord, ans, path);
        return ans;
    }
};