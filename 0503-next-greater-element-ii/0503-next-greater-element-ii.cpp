class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //Treat nums array as double
        //1,2,3,4,1,2,3,4
        //now find nge for all
        //while accessing i%n
        int n=nums.size();
        vector<int>ans(n);
        stack<int>s;
        for(int i=2*n-1;i>=0;i--){
            while(s.size()>0 && nums[i%n]>=s.top()){
                s.pop();     //removing smaller values
            }
            if(s.empty()){
                ans[i%n]=-1;
            }else{
                ans[i%n]=s.top();
            }
            s.push(nums[i%n]);
        }
        return ans;
    }
};