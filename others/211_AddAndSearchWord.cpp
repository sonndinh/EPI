class WordDictionary {
private:    
    struct TrieNode {
        bool isWord = false;
        TrieNode* children[26] = {nullptr};
    };
    
    TrieNode *root = nullptr;
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); ++i) {
            int idx = word[i] - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode;
            }
            curr = curr->children[idx];
        }
        
        curr->isWord = true;
    }
    
    // Visit character i-th of the word.
    bool visit(TrieNode *curr, string& word, int i) {
        if (i == word.size()) {
            return curr->isWord;
        }
        
        if (word[i] != '.') {
            int idx = word[i] - 'a';
            if (!curr->children[idx])
                return false;
            
            return visit(curr->children[idx], word, i+1);
        } else { // This is a wildcard character.
            for (int j = 0; j < 26; ++j) {
                if (curr->children[j]) {
                    if (visit(curr->children[j], word, i+1)) 
                        return true;
                }
            }
            return false;
        }
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        TrieNode *curr = root;
        return visit(curr, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
