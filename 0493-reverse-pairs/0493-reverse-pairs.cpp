class Solution {
public:
    int merge(vector<int>&nums,int st,int mid,int end){
        vector<int>temp;
        int i=st,j=mid+1;
        int invcount=0;

        //count reverse pairs
        while(i<=mid){
            while(j<=end && (long long)nums[i]>2LL*nums[j]){
                j++;
            }
            invcount+=j-(mid+1);
            i++;
        }

        //reset pointers
        i=st;
        j=mid+1;

        //normal merge
        while(i<=mid && j<=end){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }else{
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }

        while(j<=end){
            temp.push_back(nums[j]);
            j++;
        }

        for(int i=0;i<temp.size();i++){
            nums[i+st]=temp[i];
        }

        return invcount;
    }

    int mergesort(vector<int>&nums,int st,int end){
        if(st<end){
            int mid=st+(end-st)/2;

            int leftinvcount=mergesort(nums,st,mid);
            int rightinvcount=mergesort(nums,mid+1,end);
            int count=merge(nums,st,mid,end);

            return leftinvcount+rightinvcount+count;
        }
        return 0;
    }

    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }
};