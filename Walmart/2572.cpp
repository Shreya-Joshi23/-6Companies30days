class Solution {
public:
    /*
        Step1:-Filter out square numbers
        Step2:-store frquency of each element in a map
            WHY? {{2,1},{3,4},{5,2}}
            subsets possible->1+4+2+(1*4)+(1*2)+(4*2) not all valid subsets
            using bitmask to find all subsets and mainintaing cprod to check if subset is valid
        Step3:-1 is considered a square free number so possible number of combinations from 1's present nC0+nC1+nC2+......+nCn=2^n
        these 1's can be combinaed with other subsets 
        so final answer=ans+=2^n+(2^n-1)
    */

    bool check(long long n){
        for(long long i=2;i*i<=169;i++){
            if(n%(i*i)==0)return false;
        }
        return true;
    }

    long long powerMod(long long base,long long exponent,long long modulus){
        long long result=1;
        base%=modulus;
        while(exponent>0){
            if(exponent&1){
                result=(result*base)%modulus;
            }
            base=(base*base)%modulus;
            exponent>>=1;
        }
        return result;
    }

    int squareFreeSubsets(vector<int>& nums) {
        int M=1e9+7;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(check(nums[i]))mp[nums[i]]++;
        }

        vector<pair<int,int>>temp;
        for(auto it:mp){
            if(it.first!=1)
                temp.push_back({it.first,it.second});
        }

        int ones=mp[1],n=temp.size();
        long long ans=0;
        mp.clear();

        for(int i=1;i<=(1<<n)-1;i++){
            long long cnt=0,cnum=1;
            for(int j=0;j<n;j++){
                if((i&(1<<j))!=0){
                    if(cnt==0)cnt=1;
                    cnt*=temp[j].second;
                    cnt%=M;
                    cnum*=temp[j].first;
                    if(cnum>LONG_MAX/30 && !check(cnum)){
                        cnt=0;
                        break;
                    }
                }
            }
            if(check(cnum))
            ans=(ans+cnt)%M;
        }

        int power=powerMod(2,ones,M);
        ans*=power;
        ans+=power-1;
        ans%=M;

        return ans;

    }
};