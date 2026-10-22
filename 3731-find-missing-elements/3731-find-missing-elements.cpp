class Solution {
public:
    int maximum(vector<int>&nums){
        int mx=INT_MIN;
        for(int i=0;i<nums.size();i++){
            mx=max(mx,nums[i]);
        }
        return mx;
    }
    int minimum(vector<int>&nums){
        int mx=INT_MAX;
        for(int i=0;i<nums.size();i++){
            mx=min(mx,nums[i]);
        }
        return mx;
    }
    vector<int> findMissingElements(vector<int>& nums) {
        
        vector<int>ans;
        int upper=maximum(nums);
        int lower=minimum(nums);
        set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int element=lower;
        while(element<=upper){
            if(s.find(element)==s.end()){
                ans.push_back(element);
            }
            element++;
        }
        return ans;
    }
};