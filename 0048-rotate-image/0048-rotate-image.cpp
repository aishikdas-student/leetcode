class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){        //TRANSPOSE
            for(int j=i+1;j<matrix.size();j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<matrix.size();i++){            //REVERSE THE ROWS
            reverse(matrix[i].begin(),matrix[i].end());
        }
        //MATRIX IS ROTATED RIGHT BY 90 DEG
    }
};