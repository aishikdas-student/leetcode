class Solution {
public:
    bool isSafe(vector<vector<char>>&board,int row,int col){
        //not in same row
        for(int c=0;c<9;c++){
            if(board[row][col]==board[row][c] && c!=col){
                return false;
            }
        }
        //not in same col
        for(int r=0;r<9;r++){
            if(board[row][col]==board[r][col] && r!=row){
                return false;
            }
        }
        //not in same grid
        int gridstrow=(row/3)*3; //IMP
        int gridstcol=(col/3)*3; //IMP
        for(int r=gridstrow;r<=gridstrow+2;r++){
            for(int c=gridstcol;c<=gridstcol+2;c++){
                if(board[row][col]==board[r][c] && r!=row && c!=col){
                    return false;
                }
            }
        }
        return true;

    }
    bool isValidSudoku(vector<vector<char>>& board) {
        bool ans=true;
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                if(board[r][c]!='.'){
                    ans=ans && isSafe(board,r,c);
                }
            }
        }
        return ans;
        
    }
};