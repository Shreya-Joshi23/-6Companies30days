class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string>st;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                string row="row"+to_string(i)+board[i][j];
                string col="col"+to_string(j)+board[i][j];
                string box="box"+to_string((i/3)*3+(j/3))+board[i][j];
                if(st.find(row)==st.end() && st.find(col)==st.end() && st.find(box)==st.end()){
                    st.insert(row);
                    st.insert(col);
                    st.insert(box);
                }else{
                    return false;
                } pair<string,int> solve(int i,int j,vector<int>&arr,vector<vector<pair<string,int>>>&dp){
        if(i==j){
            string s="";
            s+='A'+i-1;
            return {s,0};
        }   
        if(dp[i][j].second!=-1)return dp[i][j];
        int mini=INT_MAX;
        string sr="";
        for(int k=i;k<j;k++){
            string s="";
            auto left=solve(i,k,arr,dp);
            auto right=solve(k+1,j,arr,dp);
            int x=left.second+right.second+arr[i-1]*arr[k]*arr[j];
            s+='('+left.first+right.first+')';
            if(mini>x){
                mini=x;
                sr=s;
            }
        }
        return dp[i][j]={sr,mini};
    }
    
    string matrixChainOrder(vector<int> &arr) {
        // code here
        /*
            [40, 20, 30, 10, 30]
            [40,20] [20,30] [30,10] [10,30]
              A        B       C       D
            [40,20]    [20,10]       [10,30]
                 [40,10]        [10,30]
                        [40,30]
            (40*10*30)+(40*20*10)+(20*30*10)
        */
        
        int n=arr.size();
        vector<vector<pair<string,int>>>dp(n,vector<pair<string,int>>(n,pair<string,int>({"",-1})));
        auto p=solve(1,n-1,arr,dp);
        return p.first;
    }
                }
            }
        }
        return true;
    }
};