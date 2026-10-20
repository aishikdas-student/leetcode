class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& A, int target) {
        int strow=0;
        int endrow=A.size()-1;
        int n=A[0].size();
        
        
        while(strow<=endrow){
            int midrow=strow+(endrow-strow)/2;
            if(A[midrow][0]<=target && target<=A[midrow][n-1]){
                //binary search inside that row
                int st=0;
                int end=n-1;
                while(st<=end){
                    int mid=st+(end-st)/2;
                    if(A[midrow][mid]==target){
                        return true;
                    }else if(A[midrow][mid]<target){
                        st=mid+1;
                    }else{
                        end=mid-1;
                    }
                }
                return false; //VERY VERY IMPORTANT 
                //RETURNS FALSE IF TARGET PRESENT IN RANGE BUT NOT MATCHES
            }else if(A[midrow][n-1]<target){
                strow=midrow+1;
            }else{
                endrow=midrow-1;
            }

        }
        return false;

    }
};