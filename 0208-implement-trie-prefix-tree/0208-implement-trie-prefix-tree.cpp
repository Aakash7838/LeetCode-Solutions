class Trie {

    // Har node ka structure
    struct TrieNode {
        TrieNode* children[26];  // a-z ke liye
        bool isEnd;              // word yahan khatam?

        TrieNode(){
            // Sab children null karo
            for(int i = 0; i < 26; i++){
                children[i] = nullptr;
            }
            isEnd = false;
        }
    };

    TrieNode* root;  // starting point

public:

    Trie(){
        root = new TrieNode();  // empty root
    }

    // ━━━━━━━━━━━━━━━━━━━━━━
    // INSERT
    // ━━━━━━━━━━━━━━━━━━━━━━
    void insert(string word) {
        TrieNode* curr = root;

        for(int i = 0; i < (int)word.size(); i++){

            // Character → index
            int idx = word[i] - 'a';

            // Agar child nahi hai → banao
            if(curr->children[idx] == nullptr){
                curr->children[idx] = new TrieNode();
            }

            // Us child pe jao
            curr = curr->children[idx];
        }

        // Word khatam → mark karo
        curr->isEnd = true;
    }

    // ━━━━━━━━━━━━━━━━━━━━━━
    // SEARCH
    // ━━━━━━━━━━━━━━━━━━━━━━
    bool search(string word) {
        TrieNode* curr = root;

        for(int i = 0; i < (int)word.size(); i++){

            int idx = word[i] - 'a';

            // Character nahi mila → word nahi
            if(curr->children[idx] == nullptr){
                return false;
            }

            curr = curr->children[idx];
        }

        // Word exist karta hai sirf jab isEnd true ho
        return curr->isEnd;
    }

    // ━━━━━━━━━━━━━━━━━━━━━━
    // STARTSWITH
    // ━━━━━━━━━━━━━━━━━━━━━━
    bool startsWith(string prefix) {
        TrieNode* curr = root;

        for(int i = 0; i < (int)prefix.size(); i++){

            int idx = prefix[i] - 'a';

            // Prefix character nahi mila → false
            if(curr->children[idx] == nullptr){
                return false;
            }

            curr = curr->children[idx];
        }

        // Prefix mila → isEnd check nahi
        return true;
    }
};