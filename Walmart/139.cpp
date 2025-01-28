class Solution {
public:

    bool solve(string s,set<string>st,vector<int>&dp,int start){
        int n=s.size();
        if(start==n)return dp[start]=true;
        if(dp[start]!=-1)return dp[start];
        for(int i=start;i<n;i++){
            string sub=s.substr(start,i+1-start);
            if(st.find(sub)!=st.end() && solve(s,st,dp,i+1)){
                return dp[start]=true;
            }
        }
        return dp[start]=false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        /*
            s="catsandog" wordDict = ["cats","dog","sand","and","cat"]
            cat + (sandog)
               sand + (og)
                 og
            cats + (andog)
              and + (og)
               og
        */

        set<string>dict;
        for(auto it:wordDict){
            dict.insert(it);
        }
        int n=s.size();
        vector<int>dp(n+1,-1);
        return solve(s,dict,dp,0);
    }
};