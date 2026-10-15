#include <stack>
class Solution {
public:
    bool ismatch(char a,stack<char> &st){
        if(st.empty()){
            return false;
        }
        if((a==')' && st.top()=='(') || (a=='}' && st.top()=='{') || (a==']' && st.top()=='[')  ){
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }else{
                if(ismatch(s[i],st)){
                    
                    st.pop();
                }else{
                    return false;
                }

            }
        }
        return st.empty()?true:false;
        
    }
};