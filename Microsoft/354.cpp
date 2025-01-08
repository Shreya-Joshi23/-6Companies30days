class Solution {
public:

    static bool comp(vector<int> &a,vector<int> &b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        int m=envelopes[0].size();
        sort(envelopes.begin(),envelopes.end(),comp);
        for(auto it:envelopes){
            cout<<it[0]<<" "<<it[1]<<endl;
        }
        
        vector<int>lis;
        for(int i=0;i<n;i++){
            auto it=lower_bound(lis.begin(),lis.end(),envelopes[i][1]);
            if(it==lis.end()){
                lis.push_back(envelopes[i][1]);
            }else{
                *it=envelopes[i][1];
            }
        }

        //tc:O(nlogn+nlogn)=O(2*nlogn)

        for(auto ele:lis){
            cout<<ele<<" ";
        }

        return lis.size();
    }
};