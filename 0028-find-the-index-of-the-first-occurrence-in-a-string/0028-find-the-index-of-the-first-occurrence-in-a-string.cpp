class Solution {
public:
    int strStr(string h, string n) {
        if(n.size()>h.size()){
            return -1;
        }
        
        int win=n.size();
        for (int i=0; i<=h.size() - win ;i++){
            int ismatch=0;
            for(int j=i,k=0;j<i+win && k<n.size();j++,k++){
                
                if(h[j]!= n[k]){
                    break;
                }else{ //match
                   ismatch++;
                   if(ismatch==win){
                    return i;
                   }
                }
            }
        }
        return -1;
    }
};