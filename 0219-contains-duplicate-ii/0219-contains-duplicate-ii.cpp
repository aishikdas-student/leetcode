class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> m; //key,index
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])!=m.end()){ //present
                if (abs(m[nums[i]] - i) <=k){
                    return true;
                }
            }  //absent
            m[nums[i]]=i;
            
        }
        return false;
    }
};