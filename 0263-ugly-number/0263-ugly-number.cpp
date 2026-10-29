class Solution {
public:
    bool isUgly(int n) {
        if(n==0){
            return false;
        }
        while(n%2==0){    //while divisible by 2 divide by 2
            n/=2;
        }
        while(n%3==0){
            n/=3;
        }
        while(n%5==0){
            n/=5;
        }
        return n==1;
    }
};