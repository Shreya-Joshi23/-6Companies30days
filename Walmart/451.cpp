class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char,int>>v(123);
        int n=s.size();
        for(int i=0;i<n;i++){
            int freq=v[s[i]].second;
            v[s[i]]={s[i],freq+1};
        }

        auto lambda=[&](pair<char,int>P1,pair<char,int>P2){
            return P1.second>P2.second;
        };

        sort(v.begin(),v.end(),lambda);
        string result="";

        for(int i=0;i<123;i++){
            int freq=v[i].second;
            int ch=v[i].first;
            if(freq>0){
                string temp=string(freq,ch);
                result+=temp;
            }
        }

        return result;

    }
};