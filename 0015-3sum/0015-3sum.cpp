class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>st;
        vector<vector<int>>ans;

        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }

            int tar=-nums[i];
            set<int>s;

            for(int j=i+1;j<nums.size();j++){
                int first=nums[j];
                int second=tar-first;

                if(s.find(second)!=s.end()){
                    vector<int>arr;
                    arr.push_back(first);
                    arr.push_back(second);
                    arr.push_back(nums[i]);

                    sort(arr.begin(),arr.end());
                    st.insert(arr);
                }

                s.insert(first);
            }
        }

        for(auto it:st){
            ans.push_back(it);
        }

        return ans;
    }
};