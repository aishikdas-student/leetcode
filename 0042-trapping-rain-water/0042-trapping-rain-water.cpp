class Solution {
public:
    vector<int> prevgreater(vector<int>&height){
        vector<int>ans;
        int maxi=0;

        for(int i=0;i<height.size();i++){
            maxi=max(maxi,height[i]);
            ans.push_back(maxi);
        }
        return ans;
    }

    vector<int> nextgreater(vector<int>&height){
        vector<int>ans(height.size());
        int maxi=0;

        for(int i=height.size()-1;i>=0;i--){
            maxi=max(maxi,height[i]);
            ans[i]=maxi;
        }
        return ans;
    }

    int trap(vector<int>& height) {
        vector<int>leftmax=prevgreater(height);
        vector<int>rightmax=nextgreater(height);

        int totalWater=0;

        for(int i=0;i<height.size();i++){
            int water=min(leftmax[i],rightmax[i])-height[i];
            totalWater+=water;
        }

        return totalWater;
    }
};