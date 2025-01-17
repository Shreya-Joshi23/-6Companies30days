class Solution {
public:

    map<vector<int>,int>mp;
    int solve(vector<int>& price, vector<vector<int>>& special, vector<int>& needs){
        int m=special.size();
        int n=needs.size();
        int cost=INT_MAX;
        vector<int>clone=needs;

        if(mp.find(needs)!=mp.end())return mp[needs];
        //check and use the ith special offer
        for(int i=0;i<m;i++){
            bool flag=true;
            int totalCost=0;
            for(int j=0;j<n;j++){
                if(special[i][j]>needs[j])flag=false;
                totalCost+=(price[j]*needs[j]);
            }
            if(flag && totalCost>special[i][n]){
                // use this special offer
                for(int j=0;j<n;j++){
                    clone[j]=needs[j]-special[i][j];
                }
                cost=min(cost,special[i][n]+solve(price,special,clone));
            }
        }
        if(cost==INT_MAX){
            cost=0;
            for(int i=0;i<n;i++){
                cost+=(price[i]*needs[i]);
            }
        }
        return mp[needs]=cost;
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        //calculate cost without any special offer
        int cost=0;
        int n=price.size();
        for(int i=0;i<n;i++){
            cost+=(price[i]*needs[i]);
        }
        cost=min(cost,solve(price,special,needs));
        return cost;
    }
};