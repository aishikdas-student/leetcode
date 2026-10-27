class Solution {
public:
    bool detectCapitalUse(string word) {
        bool ans1=false,ans2=false,ans3=false,ans4=false;
        if(word[0]>='A' && word[0]<='Z' ){ //first letter capital
            ans1=true; //all are capital
            for(int  i=1;i<word.size();i++){
                if(word[i]>='a' && word[i]<='z'){
                    ans1=false;
                    break;
                }
            }
            ans2=true;//rest are small
            for(int  i=1;i<word.size();i++){
                if(word[i]>='A' && word[i]<='Z'){
                    ans2=false;
                    break;
                }
            }
            ans3=ans1 || ans2;

        }else{ //first letter small
        //so all the rest should be small as well
            ans4=true;
            for(int i=1;i<word.size();i++){
                if(word[i]>='A' && word[i]<='Z'){
                    ans4=false;
                    break;
                }
            }

        }
        return ans3 || ans4;
    }
};