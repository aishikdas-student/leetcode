class Solution {
public:
    void helper(vector<int>&candidates,int target,int idx,vector<vector<int>>&ans,vector<int>&combin,set<vector<int>> &s){
        if(target==0){
            if(s.find(combin)==s.end()){ //not present in set
                s.insert(combin);
                ans.push_back(combin);
                return ;
     
            }
            
        }
        if(idx==candidates.size() || target<0){
            return;
        }
        
        //now we have 3 choices
        combin.push_back(candidates[idx]);
        //include this element once
        helper(candidates,target-candidates[idx],idx,ans,combin,s);
        //inlcude this element multiple times
       
        combin.pop_back(); //backtracking
        //exclude
        helper(candidates,target,idx+1,ans,combin,s);
        


    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combin={};
        set<vector<int>> s;
        helper(candidates,target,0,ans,combin,s);
        return ans;
    }
};