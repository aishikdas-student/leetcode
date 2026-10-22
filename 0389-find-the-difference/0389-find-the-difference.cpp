class Solution {
public:
    char findTheDifference(string s, string t) {
        char ch;
        int freq[26]={0};      //use freq array

        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }

        for(int i=0;i<t.size();i++){
            freq[t[i]-'a']--;

            if(freq[t[i]-'a']<0){
                ch=t[i];
                break;
            }
        }

        return ch;
    }
};