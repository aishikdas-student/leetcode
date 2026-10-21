class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;   //first,target-first
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int first=nums[i];
            int second = target - first;
            if(m.find(second)!=m.end()){ //if present
                ans.push_back(i);
                ans.push_back(m[second]);
                break;

            }
            //if absent
            m[first]=i;
        }
        return ans;
    }
};