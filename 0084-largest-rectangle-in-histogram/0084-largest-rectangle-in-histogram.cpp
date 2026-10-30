class Solution {
public:
    vector<int> nextsmaller(vector<int>&heights){
        stack<int>s;
        vector<int>ans;
        for(int i=heights.size()-1;i>=0;i--){
            while(s.size()>0 && heights[i]<=heights[s.top()]){
                s.pop();     //removing greater elements 
            }
            if(s.empty()){
                ans.push_back(heights.size());//here like this else normally it is -1
            }else{
                ans.push_back(s.top());
            }
            s.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    vector<int> prevsmaller(vector<int>&heights){
        stack<int>s;
        vector<int>ans;
        for(int i=0;i<heights.size();i++){
            while(s.size()>0 && heights[i]<=heights[s.top()]){
                s.pop();     //removing greater elements 
            }
            if(s.empty()){
                ans.push_back(-1);
            }else{
                ans.push_back(s.top());
            }
            s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> rightboundary=nextsmaller(heights);
        vector<int> leftboundary=prevsmaller(heights);
        int maxArea=INT_MIN,currArea;
        for(int i=0;i<heights.size();i++){
            int width=rightboundary[i]-leftboundary[i]-1;
            currArea=heights[i]*width;
            maxArea=max(maxArea,currArea);
        }
        return maxArea;
    }
};