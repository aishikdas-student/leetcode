class Solution {
public:
    bool isPalindrome(int x) {
        vector<char> nums;
        long long copy;
        if(x<0){
            copy=-(long long)x;
        }else{
            copy=x;
        }
        
        while(copy>0){
            char rem=(copy%10)+'0';
            nums.push_back(rem);
            copy/=10;

        }
        if(x<0){
            nums.push_back('-');
        }
        
        long long rev=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!='-'){
                rev*=10;
                rev+=nums[i]-'0'+0;
                
            }else{
                rev=0;
            }


        }
        return x==rev?true:false;
    }
};