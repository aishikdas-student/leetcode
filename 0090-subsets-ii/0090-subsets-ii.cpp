class Solution {
public:
    void printsub(vector<int>&nums, vector<int> &sub,vector<vector<int>>&allsub,int i){
        
        if(i==nums.size()){
            allsub.push_back(sub);
            return ;
        }
        //include i
        sub.push_back(nums[i]);
        printsub(nums,sub,allsub,i+1);
        //exclude i
        sub.pop_back();
        int idx=i+1;
        while(idx<nums.size() && nums[idx]==nums[i]){ //skipping through dup values
            idx++;
        }
        printsub(nums,sub,allsub,idx);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> sub={};
        vector<vector<int>> allsub;
        printsub(nums,sub,allsub,0);
        return allsub;

    }
};