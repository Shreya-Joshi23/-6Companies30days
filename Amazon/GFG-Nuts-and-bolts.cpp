class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        // code here
        map<char,int>mp={{'!',0},{'#',1},{'$',2},{'%',3},{'&',4},{'*',5},{'?',6},{'@',7},{'^',8}};
        
        auto cmp=[&](char a,char b){
            return mp[a]<mp[b];
        };
        
        sort(nuts,nuts+n,cmp);//nlogn
        sort(bolts,bolts+n,cmp);//nlogn
        
    }
};