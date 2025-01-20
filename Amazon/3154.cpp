class Solution {
public:
    unordered_map<string,int>mp;
    int solve(int currstair,int jumps,int canjumpback,int k){
        if(currstair>k+1)return 0;
        int ways=0;
        string str=to_string(currstair)+"_"+to_string(jumps)+"_"+to_string(canjumpback);
        if(mp.find(str)!=mp.end())return mp[str];
        if(currstair==k){
            ways++;
        }
        if(canjumpback){
            ways+=solve(currstair-1,jumps,0,k);
        }
        ways+=solve(currstair+(1<<jumps),jumps+1,1,k);
        return mp[str]=ways;
    }

    int waysToReachStair(int k) {
        /*
            k=0  jump=1 (0+2^0=1) ways=2(0+2^1=2)
            0 1 2 3 4 5 6 7 8 9 10
                    k     
        */
        return solve(1,0,1,k);
    }
};