class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;

        sort(nums.begin(),nums.end());
        vector<int>dp(n,1),hash(n,1);
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev_idx=0;prev_idx<i;prev_idx++){
                if(nums[i]%nums[prev_idx]==0 && dp[i]<dp[prev_idx]+1){
                    dp[i]=dp[prev_idx]+1;
                    hash[i]=prev_idx;
                }
            }
        }

        for(auto ele:dp)cout<<ele<<" ";

        // finding maximum element in dp
        int maxidx=-1;
        int maxi=-1;
        for(int i=0;i<n;i++){
            if(dp[i]>maxi){
                maxidx=i;
                maxi=dp[i];
            }
        }

        ans.push_back(nums[maxidx]);
        while(hash[maxidx]!=maxidx){
            maxidx=hash[maxidx];
            ans.push_back(nums[maxidx]);
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};