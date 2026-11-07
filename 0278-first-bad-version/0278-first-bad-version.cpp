// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int helper(int n,int st,int end){
        if(st==end){
            return st;
        }
        while(st<end){
            
            int mid=st+(end-st)/2;
            if(isBadVersion(mid)){ //true => is bad and real bad could be before mid
                
                return helper(n,st,mid);
            }else{
                return helper(n,mid+1,end);
            }
        }
        return -1;
    }
    int firstBadVersion(int n) {
        return helper(n,1,n);
    }
};