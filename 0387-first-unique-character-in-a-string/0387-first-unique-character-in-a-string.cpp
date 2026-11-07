class Solution {
public:
    int firstUniqChar(string str) {
       unordered_map<char,int> m; //ch,freq
       queue<int>q;
       for(int i=0;i<str.size();i++){ //storing ch and freq in queue
        if(m.find(str[i])==m.end()){ //absent
            q.push(i);
            m[str[i]]=1;
        }else{
            m[str[i]]++; //freq++
        }
       } 
       while(q.size()>0 && m[str[q.front()]]>1){  //removing chars with freq>1
        q.pop();
       }
       if(q.size()>0){
        return q.front();
       }else{
        return -1;
       }
    }
};