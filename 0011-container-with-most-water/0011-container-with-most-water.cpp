class Solution {
public:
    int maxArea(vector<int>& height) {
        int area=0;
        int st=0,end=height.size()-1;
        while(st<end){
            int h=min(height[st],height[end]);
            int b=end-st;
            area=max(area,h*b);
            if(height[st]<height[end]){
                st++;
            }else{
                end--;
            }
        }
        return area;
    }
};