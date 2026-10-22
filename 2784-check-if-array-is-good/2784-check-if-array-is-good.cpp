class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size();
        vector<int>freq(n,0);
        for(int i=0;i<n;i++){
            int idx=nums[i];
            if(idx<=0 || idx>=n){
                return false;
            }
            freq[idx]++;
            
        }
        for(int i=1;i<n;i++){
            if(freq[i]!=1 && i!=n-1){   //from 1 to n-1 all have freq 1
                return false;
            }
            if(freq[i]>1 && i!=n-1){
                return false;
            }
        }
        return true;

    }
};