class Solution {
public:
    bool isFreqSame(vector<int>freq1,vector<int>freq2){
        for(int i=0;i<freq1.size();i++){
            if(freq1[i]!=freq2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26,0);
        for(int i=0;i<s1.length();i++){
            freq1[s1[i]-'a']++;
        }
        int windsize=s1.length();
        for(int i=0;i<s2.length();i++){
            int idx=i,windidx=0;
            vector<int> windfreq(26,0);
            while(windidx<windsize && idx<s2.length()){
                windfreq[s2[idx]-'a']++;
                windidx++;
                idx++;
            }
            if(isFreqSame(freq1,windfreq)){
                return true;
            }
        }
        return false;
    }
};