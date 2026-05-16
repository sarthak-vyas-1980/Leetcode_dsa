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
        if(word.length()==0){
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        TrieNode* temp = root->next[index];
        if(!temp){
            return false;
        }
        else return checkWord(word.substr(1, word.length()-1), temp);
    }
};
class Solution {
public:
    vector<string> ans;
    int rows, cols;

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, string currWord) {
        if(i < 0 || j < 0 || i >= rows || j >= cols) return;
        char ch = board[i][j];

        if(ch == '#') return;
        int index = ch - 'a';

        if(node->next[index] == NULL) return;
        node = node->next[index];
        currWord += ch;

        if(node->isTerminal) {
            ans.push_back(currWord); // Word found
            node->isTerminal = false; // Prevent duplicates
        }

        board[i][j] = '#';
        dfs(board, i + 1, j, node, currWord);
        dfs(board, i - 1, j, node, currWord);
        dfs(board, i, j + 1, node, currWord);
        dfs(board, i, j - 1, node, currWord);

        board[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie('\0');
        if(words.empty()) return words; 
        for(int i=0; i<words.size(); i++){
            trie->addWord(words[i], trie->root);
        }
        
        rows = board.size();
        cols = board[0].size();
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                dfs(board, i, j, trie->root, "");
            }
        }
        return ans;
    }
};