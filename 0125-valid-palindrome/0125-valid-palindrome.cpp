class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()==0){
            return true;
        }
        string str="";
        
        for(int i=0;i<s.length();i++){
            if(s[i]>='a'&& s[i]<='z'){ //lower
                str.push_back(s[i]);
                
            }
            else if(s[i]>='A'&& s[i]<='Z'){  //upper
                str.push_back((s[i]+32));
                
            }
            else if(s[i]>='0' && s[i]<='9'){ //number
                str.push_back(s[i]);
                
            }
        }
        int st=0,end=str.length()-1;
        while(st<end){
            if(str[st]!=str[end]){
                return false;
            }
            st++;
            end--;

        }
        return true;

    }
};