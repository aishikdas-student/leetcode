class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {

        //compare largest and not smallest

        int idx=m+n-1;
        int i=m-1;
        int j=n-1;

        while(i>=0 && j>=0){
            if(A[i]>=B[j]){
                A[idx]=A[i];
                idx--;
                i--;
            }else{
                A[idx]=B[j];
                idx--;
                j--;
            }
        }
        if(i<0){
            while(j>=0){
                A[idx]=B[j];
                idx--;
                j--;

            }
            
        }
        if(j<0){
            while(i>=0){
                A[idx]=A[i];
                idx--;
                i--;

            }
            
        }

    }
};