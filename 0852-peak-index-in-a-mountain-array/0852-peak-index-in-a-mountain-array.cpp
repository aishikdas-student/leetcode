class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int idx=-1;
        /*for(int i=1;i<arr.size()-1;i++){
            if(arr[i-1]<arr[i] && arr[i]>arr[i+1]){
                idx=i;;
            }
        }
        return idx;*/
        //above is o(n)

        int st=1,mid,end=arr.size()-2; //since peak cant be at the beg or end
        while(st<=end){
            mid=st+(end-st)/2;
            if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){
                return mid;
            }else if(arr[mid-1]<arr[mid]){
                st=mid+1;
            }else{
                end=mid-1;
            }
        }      
        return -1;
    }
};