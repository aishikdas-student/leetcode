class Solution {
public:
    int subarraySum(vector<int>& nums, int tar) {
        int n=nums.size();
        vector<int>PS (n,0);
        PS[0]=nums[0];
        int count=0;
        for(int i=1;i<nums.size();i++){
            PS[i]=PS[i-1]+nums[i];
        }
        unordered_map<int,int> m; //PS,freq
        for(int i=0;i<n;i++){
            if(PS[i]==tar){
                count++;
            }
            int val=PS[i]-tar; //find this val in map
            if(m.find(val)!=m.end()){    // if val present
                count+=m[val];
            }
            if(m.find(PS[i])==m.end()){ //absent then initialise 
                m[PS[i]]=0;
            }
            m[PS[i]]++;
        }
        return count;

    }
};