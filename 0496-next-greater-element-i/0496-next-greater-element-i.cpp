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
        unordered_map<int,int> m; //element,nge
        for(int i=0;i<ans.size();i++){
            m[nums2[i]]=ans[i];
        }
        for(int i=0;i<ans1.size();i++){
            ans1[i]=m[nums1[i]];
        }
        return ans1;

    }
};