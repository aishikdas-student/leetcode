class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftprod(nums.size());
        vector<int> rightprod(nums.size());
        vector<int>ans(nums.size());
        
        leftprod[0]=1;
        rightprod[nums.size()-1]=1;
        
        for(int i=1;i<nums.size();i++){
            leftprod[i]=leftprod[i-1]*nums[i-1];
        }

        for(int i=nums.size()-2;i>=0;i--){
            rightprod[i]=rightprod[i+1]*nums[i+1];
        }

        for(int i=0;i<nums.size();i++){
            ans[i]=leftprod[i]*rightprod[i];
        }
        return ans;
    }
};