class Trie {
    struct TrieNode{
        TrieNode* children[26];
        bool isEnd;

        TrieNode(){
            for(int i = 0; i < 26; i++){
                children[i] = NULL;
            }
            isEnd = false;
        }
    };

    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;

        for(int i = 0; i < word.size(); i++){
            int idx = word[i] - 'a';

            if(curr->children[idx] == NULL){
                curr->children[idx] = new TrieNode();
            }
            
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        
        for(int i = 0; i < word.size(); i++){
            int idx = word[i] - 'a';

            if(curr->children[idx] == NULL){
                return false;
            }

            curr = curr->children[idx];
        }

        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;

        for(int i = 0; i < prefix.size(); i++){
            int idx = prefix[i] - 'a';

            if(curr->children[idx] == NULL){
                return false;
            }

            curr = curr->children[idx];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */