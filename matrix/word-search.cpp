class Solution {
private:
    bool helper(int x, int y, vector<vector<char>> &b, string s, int k){
        if(k == s.size()) return true;
        if(x >= b.size() || y >= b[0].size() || x<0 || y<0 || b[x][y] == '#' || b[x][y]!=s[k]){
            return false;
        }
        char a = b[x][y];
        b[x][y] = '#';
        bool ans = false;
        ans |= helper(x+1, y, b, s, k+1);
        ans |= helper(x-1, y, b, s, k+1);
        ans |= helper(x, y-1, b, s, k+1);
        ans |= helper(x, y+1, b, s, k+1);
        b[x][y] = a;
        return ans;
    }   
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                if(board[i][j] == word[0]){
                    if(helper(i, j, board, word, 0)) return true;
                }        
            }
        }
        return false;
    }
};