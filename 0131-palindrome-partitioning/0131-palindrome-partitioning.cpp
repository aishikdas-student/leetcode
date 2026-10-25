class Solution {
public:
    bool isPalindrome(string st){
        int start=0,end=st.size()-1;
        while(start<end){
            if(st[start]!=st[end]){
                return false;
            }
            start++;
            end--;
        }
        
        return true;
    }
    void helper(string s,vector<string> &part,vector<vector<string>>&ans){
        if(s==""){
            ans.push_back(part);
            return;
        }
        for(int i=0;i<s.size();i++){
            if(isPalindrome(s.substr(0,i+1))){
                part.push_back(s.substr(0,i+1));
                helper(s.substr(i+1),part,ans);
                part.pop_back();//backtrack
            }
        }


    }
    vector<vector<string>> partition(string s) {
        vector<string>part;
        vector<vector<string>> ans;
        helper(s,part,ans);
        return ans;


        
    }
};