class Solution {
public:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;
        string word;  // word store karo directly

        TrieNode(){
            for(int i = 0; i < 26; i++){
                children[i] = nullptr;
            }
            isEnd = false;
            word  = "";
        }
    };

    TrieNode* root;
    vector<string> result;

    void insert(string& word){
        TrieNode* curr = root;
        for(char c : word){
            int idx = c - 'a';
            if(curr->children[idx] == nullptr){
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
        curr->word  = word;  // node pe word save
    }

    void dfs(vector<vector<char>>& grid,
             int i, int j,
             TrieNode* node,
             vector<vector<bool>>& visited){

        // Boundary check
        if(i<0 || i>=(int)grid.size() ||
           j<0 || j>=(int)grid[0].size()){
            return;
        }

        // Already visited
        if(visited[i][j]) return;

        char c = grid[i][j];
        int  idx = c - 'a';

        // Trie mein valid prefix nahi → PRUNE
        if(node->children[idx] == nullptr) return;

        // Aage badho
        node = node->children[idx];
        visited[i][j] = true;

        // Word mila?
        if(node->isEnd){
            result.push_back(node->word);
            node->isEnd = false;  // duplicate avoid
        }

        // 4 directions
        dfs(grid, i-1, j, node, visited);  // up
        dfs(grid, i+1, j, node, visited);  // down
        dfs(grid, i,   j-1, node, visited);  // left
        dfs(grid, i,   j+1, node, visited);  // right

        // Backtrack
        visited[i][j] = false;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        int rows = (int)board.size();
        int cols = (int)board[0].size();

        // Step 1: Trie banao
        root = new TrieNode();
        for(string& word : words){
            insert(word);
        }

        // Step 2: Visited array
        vector<vector<bool>> visited(
            rows, vector<bool>(cols, false)
        );

        // Step 3: Har cell se DFS
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                dfs(board, i, j, root, visited);
            }
        }

        return result;
    }
};