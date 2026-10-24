class Solution {
public:
    bool isSafe(vector<vector<char>>&board,int row,int col,int dig){
        //not in same row
        for(int c=0;c<9;c++){
            if(dig==board[row][c] ){
                return false;
            }
        }
        //not in same col
        for(int r=0;r<9;r++){
            if(dig==board[r][col] ){
                return false;
            }
        }
        //not in same grid
        int gridstrow=(row/3)*3; //IMP
        int gridstcol=(col/3)*3; //IMP
        for(int r=gridstrow;r<=gridstrow+2;r++){
            for(int c=gridstcol;c<=gridstcol+2;c++){
                if(dig==board[r][c] ){
                    return false;
                }
            }
        }
        return true;

    }
    bool sudoku(vector<vector<char>>&board,int row,int col){
        if(row==9){
            return true;
        }
        int nextrow=row;
        int nextcol=col+1;
        if(nextcol==9){
            nextrow=row+1;
            nextcol=0;
        }
        if(board[row][col]!='.'){//a digit
            return sudoku(board,nextrow,nextcol);
        }
        //if not a digit we have to place a digit
        for(char dig='1';dig<='9';dig++){
            if(isSafe(board,row,col,dig)){
                board[row][col]=dig;
                if(sudoku(board,nextrow,nextcol)){
                    return true;
                }
                board[row][col]='.'; //backtrack
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        sudoku(board,0,0);
        
    }
};