class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int st=0,end=n-1,mid;
        if(n==1){
            return nums[0];
        }
        while(st<=end){
            mid=st+(end-st)/2;
            if(mid==0 && nums[0]!=nums[1]){
                return nums[mid];
            }
            if(mid==n-1 && nums[mid-1]!=nums[mid]){
                return nums[mid];
            }
            if(nums[mid-1]!=nums[mid] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            if(mid%2==0){ //mid is even , both sides are even
                if(nums[mid-1]==nums[mid]){
                    end=mid-1;
                }else{
                    st=mid+1;
                }
            }else{ //mid is odd ,both sides odd
                if(nums[mid-1]==nums[mid]){
                    st=mid+1;
                }else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};