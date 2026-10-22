class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_set<int>s;
        vector<int> ans;
        int gridsum=0;
        int n=grid.size();
        int expsum=(n*n)*(n*n + 1)/2;
        int a; //repeats twice
        int b; //missing
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                gridsum+=grid[i][j];
                if(s.find(grid[i][j])!=s.end()){ //present
                    a=grid[i][j];
                    ans.push_back(a);
                    
                }else{
                    s.insert(grid[i][j]);
                }
            }
        }
        // gridsum -a +b = expsum
        b = expsum +a -gridsum;
        ans.push_back(b);
        return ans;
    }
};