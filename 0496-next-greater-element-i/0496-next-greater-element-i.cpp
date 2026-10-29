class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        vector<int> ans;
        for(int i=nums2.size()-1;i>=0;i--){
            while(s.size()>0 && s.top()<=nums2[i]){ //removing smaller from right
                s.pop();
            }
            if(s.empty()){ //no next greater element
                ans.push_back(-1);
            }else{
                ans.push_back(s.top());
            }
            s.push(nums2[i]);
        }
        reverse(ans.begin(),ans.end());
        //now ans contains all the NGE for all elements of nums2
        //ans=[3,4,-1,-1]
        vector<int>ans1(nums1.size());
        for(int i=0;i<nums1.size();i++){
            
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    ans1[i]=ans[j];

                }
            }
        }
        return ans1;

    }
};