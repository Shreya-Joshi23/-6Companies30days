class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size();
        int m=img[0].size();
        vector<vector<int>>ans(n,vector<int>(m));

        int dx[]={-1,0,1,1,1,0,-1,-1};
        int dy[]={1,1,1,0,-1,-1,-1,0};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int currsum=img[i][j];
                int cnt=1;
                for(int k=0;k<8;k++){
                    int x=i+dx[k];
                    int y=j+dy[k];
                    if(x>=0 && x<n && y>=0 && y<m){
                        currsum+=img[x][y];
                        cnt++;
                    }
                }
                int res=floor(currsum/cnt);
                ans[i][j]=res;
            }
        }

        //tc:O(n*m*8)
        return ans;
    }
};