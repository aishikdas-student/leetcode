class Solution {
public:
    bool helper(vector<vector<int>>&grid,int row,int col,int expVal){
        int n = grid.size();

        if(row < 0 || col < 0 || row >= n || col >= n){ //boundary conditions
            return false;
        }
        if(grid[row][col]!=expVal){ //if not match with expval
            return false;
        }
        if(expVal==n*n-1){ //final value also got
            return true;
        }
        bool ans1=helper(grid,row-2,col+1,expVal+1);
        bool ans2=helper(grid,row-1,col+2,expVal+1);
        bool ans3=helper(grid,row+1,col+2,expVal+1);
        bool ans4=helper(grid,row+2,col+1,expVal+1);
        bool ans5=helper(grid,row+2,col-1,expVal+1);
        bool ans6=helper(grid,row+1,col-2,expVal+1);
        bool ans7=helper(grid,row-1,col-2,expVal+1);
        bool ans8=helper(grid,row-2,col-1,expVal+1);

        return ans1||ans2||ans3||ans4||ans5||ans6||ans7||ans8;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        return helper(grid,0,0,0);

        
    }
};