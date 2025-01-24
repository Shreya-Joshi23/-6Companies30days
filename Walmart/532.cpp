class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int pairs=0;
        map<int,int>mp;
        for(auto x:nums)
            mp[x]++;

        for(auto it:mp){
            if(k==0){
                if(it.second>1)pairs++;
            }else{
                if(mp.find(it.first+k)!=mp.end())pairs++;
            }
        }

        return pairs;
    }
};