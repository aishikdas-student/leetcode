class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int strow=0, stcol=0, endrow=matrix.size()-1, endcol=matrix[0].size()-1;
        while(strow<=endrow && stcol<=endcol){
            for(int i=stcol;i<=endcol;i++){
                ans.push_back(matrix[strow][i]);    //TOP
            }
            for(int i=strow+1;i<=endrow;i++){

                ans.push_back(matrix[i][endcol]);    //RIGHT
            }
            for(int i=endcol-1;i>=stcol;i--){
                if(strow==endrow){
                    break;
                }
                ans.push_back(matrix[endrow][i]);    //BOTTOM
            }
            for(int i=endrow-1;i>=strow+1;i--){
                if(stcol==endcol){
                    break;
                }
                ans.push_back(matrix[i][stcol]);    //LEFT
            }
            strow++;endrow--;
            stcol++;endcol--;
        }
        return ans;
    }
};