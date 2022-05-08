class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int ROWS = board.size();
        int COLS = board[0].size();
        if (word.size() > ROWS * COLS)
            return false;
        
        for (int r = 0; r < ROWS; r++)
            for (int c = 0; c < COLS; c++)
                if (dfs (board, word, r, c, 0))
                    return true;
        
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string word, int r, int c, int i) {
        if (i == word.size())
            return true;
        
        bool res = false;
        int ROWS = board.size();
        int COLS = board[0].size();

        if (r < 0 || c < 0 || 
            r >= ROWS || c >= COLS ||
            board[r][c] != word[i])
            return false;
            
        char curr = board[r][c];
        board[r][c] = '-';        // mark path
        res = (dfs(board, word, r, c+1, i+1) ||
               dfs(board, word, r, c-1, i+1) ||  
               dfs(board, word, r+1, c, i+1) ||
               dfs(board, word, r-1, c, i+1));

        board[r][c] = curr;       // mark back the original board value
        return res;
            
    }
};
