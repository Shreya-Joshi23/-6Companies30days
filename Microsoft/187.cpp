class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        vector<string>ans;
        map<string,int>mp;
        int n=s.size();

        for(int i=0;i<=n-10;i++){
            string sub=s.substr(i,10);
            cout<<sub<<endl;
            mp[sub]++;
        }

        for(auto it:mp){
            if(it.second>1){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};