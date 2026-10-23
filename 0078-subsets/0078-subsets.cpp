class Solution {
public:
    void printsub(vector<int> &nums,vector<int> &sub,vector<vector<int>> &allSub,int i){
        if(i==nums.size()){
            allSub.push_back(sub);
            return;
        }
        //include
        sub.push_back(nums[i]);
        printsub(nums,sub,allSub,i+1);
        //exclude
        sub.pop_back();
        printsub(nums,sub,allSub,i+1);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sub={};
        vector<vector<int>> allSub;
        printsub(nums,sub,allSub,0);
        return allSub;


    }
};