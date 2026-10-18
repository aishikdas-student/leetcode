class Solution {
public:
    void sortColors(vector<int>& nums) {

        //DUTCH NATIONAL FLAG ALGO
        // 0 to l-1 all zeros
        // l to m-1 all ones
        // m to h-1 all twos
        
        int n=nums.size();
        int low=0,mid=0,high=n-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }else if(nums[mid]==1){
                mid++;
            }else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    
    }
};