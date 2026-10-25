class Solution {
public:
    void helper(vector<int>&candidates,int target,int idx,vector<vector<int>>&ans,vector<int>&combin){
        if(target==0){
            
                
                ans.push_back(combin);
                return ;
     
           
            
        }
        if(idx==candidates.size() || target<0){
            return;
        }
        
        //now we have 2 choices
        combin.push_back(candidates[idx]); //include once
        
        helper(candidates,target-candidates[idx],idx,ans,combin);//check if again possible
        
       
        combin.pop_back(); //backtracking
        //exclude
        helper(candidates,target,idx+1,ans,combin);
        


    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combin={};
        set<vector<int>> s;
        helper(candidates,target,0,ans,combin);
        return ans;
    }
};