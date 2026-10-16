class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int bestbuy=prices[0];
        int maxP=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]>bestbuy){
                maxP=max(maxP,prices[i]-bestbuy);
            }else{
                bestbuy=prices[i];
            }

        }
        return maxP;
    }
};