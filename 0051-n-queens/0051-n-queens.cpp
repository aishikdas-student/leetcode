class Solution {
public:
//WE HAVE TO PLACE N QUEENS IN N ROWS
    bool isSafe(vector<string>&board,int row,int col){
        int n=board.size();
        //not same row
        for(int c=0;c<n;c++){
            if(board[row][c]=='Q'){
                return false;
            }
        }
        //not same col
        for(int r=0;r<n;r++){
            if(board[r][col]=='Q'){
                return false;
            }
        }
        //not in primary upper diag
        for(int r=row-1,c=col-1;r>=0 && c>=0;r--,c--){
            
            
            if(board[r][c]=='Q'){
                return false;
            }
                
            
        }
        //not in secondary upper diag
        for(int r=row-1,c=col+1;r>=0 && c<n;r--,c++){
            
            if(board[r][c]=='Q'){
                return false;
            }
                
            
        }
        return true;

    }
    void nqueens(vector<string>&board,vector<vector<string>>&ans, int row,int n){
        if(row==n){                 //base case
            ans.push_back(board);
            return;
        }
        for(int j=0;j<n;j++){
            if(isSafe(board,row,j)){
                board[row][j]='Q';
                nqueens(board,ans,row+1,n); //base case will meet when row==n so dont -- n
                board[row][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.')); //"....","....","....","...."
        vector<vector<string>> ans;
        nqueens(board,ans,0,n);
        return ans;


    }
};