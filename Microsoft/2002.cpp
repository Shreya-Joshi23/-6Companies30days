class Solution {
public:
    int maxProduct(string s) {
        /*
            We have to create two PALINDROMIC subsequences s1 and s2 not taking a particular index character at both s1 and s2 and maximize the product of lenghts of both strings
        */

        int n=s.length();
        map<int,int>mp;
        for(int mask=0;mask<(1<<n);mask++){
            string sub="";
            for(int i=0;i<n;i++){
                if(mask&(1<<i)){
                    sub+=s[i];
                }
            }
            string temp=sub;
            reverse(sub.begin(),sub.end());
            if(sub==temp){
                mp[mask]=sub.length();
            }
        }

        int res=0;
        for(auto it1:mp){
            for(auto it2:mp){
                if((it1.first & it2.first)==0){
                    res=max(res,it1.second * it2.second);
                }
            }
        }

        return res;
    }
};