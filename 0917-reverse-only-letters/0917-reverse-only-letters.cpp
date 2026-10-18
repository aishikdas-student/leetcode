#include<string>
class Solution {
public:
    bool isAlpha(char ch){
        if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')){
            return true;
        }
        return false;
    }
    string reverseOnlyLetters(string s) {
        int st=0,end=s.size()-1;
        while(st<end){
            if(!isAlpha(s[st])){
                st++;
            }
            else if(!isAlpha(s[end])){
                end--;
            }else{
                swap(s[st],s[end]);
                st++;
                end--;
            }
        }
        return s;

    }
};