class Solution {
public:

    int solve(int idx,bool buy,int cnt,vector<int>&prices,vector<vector<vector<int>>>&dp){
        int n=prices.size();
        int profit=0;
        if(idx==n||cnt==0){
            return 0;
        }
        if(dp[idx][buy][cnt]!=-1)return dp[idx][buy][cnt];
        if(buy){
            //can buy
            int pick=-prices[idx]+solve(idx+1,false,cnt,prices,dp);
            int notpick=0+solve(idx+1,true,cnt,prices,dp);
            profit=max(pick,notpick);
        }else{
            //sell
            int pick=prices[idx]+solve(idx+1,true,cnt-1,prices,dp);
            int notpick=0+solve(idx+1,false,cnt,prices,dp);
            profit=max(pick,notpick);
        }
        return dp[idx][buy][cnt]=profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        /*
            Complete at most k transactions(buy and sell) to find maximum profit
            (idx,buy,cnt,currprofit,prices,k)
            if(buy=0)
            buy or not buy
            else
            sell or not sell
        */
        int maxi=INT_MIN;
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        // TABULATION APPROACH
        for(int idx=n-1;idx>=0;idx--){
            // bool buy=true;
            for(int buy=0;buy<2;buy++){
                for(int cnt=1;cnt<k+1;cnt++){
                    int profit=0;
                    if(buy){
                //can buy
                        int pick=-prices[idx]+dp[idx+1][false][cnt];
                        int notpick=0+dp[idx+1][true][cnt];
                        profit=max(pick,notpick);
                    }else{
                        //sell
                        int pick=prices[idx]+dp[idx+1][true][cnt-1];
                        int notpick=0+dp[idx+1][false][cnt];
                        profit=max(pick,notpick);
                    }
                    dp[idx][buy][cnt]=profit;
                }
            }
        }
        // maxi=max(maxi,solve(0,true,k,prices,dp));
        // return maxi;
        return dp[0][true][k];
    }

    // Time Complexity:-O(n*2*k)
};