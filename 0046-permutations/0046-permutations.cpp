class Solution {
public:
    vector<int> nextPermutation(vector<int>&nums){
        int piv=-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                piv=i;
                break;
            }
        }
        if(piv==-1){
            reverse(nums.begin(),nums.end());
            return nums;
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]>nums[piv]){
                swap(nums[i],nums[piv]);
                break;
            }
        }
        reverse(nums.begin()+piv+1,nums.end());
        return nums;
    }
    int facto(int n){
        int f=1;
        for(int i=1;i<=n;i++){
            f*=i;
        }
        return f;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        int factorial=facto(n);
        for(int i=0;i<factorial;i++){
            vector<int> arr=nextPermutation(nums);
            ans.push_back(arr);
        }
        return ans;

        
    }
};