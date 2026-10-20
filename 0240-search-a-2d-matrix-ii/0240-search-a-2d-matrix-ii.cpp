class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int tar) {
        int m=matrix.size();
        int n=matrix[0].size();
        int r=0;
        int c=n-1;
        while(r<m && c>=0){
            int mid=matrix[r][c];
            if(mid==tar){
                return true;
            }else if(mid<tar){
                r++;
            }else{
                c--;
            }
        }
        return false;
    }
};