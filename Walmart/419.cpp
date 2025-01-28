class Solution {
public:

    // int dx[4]={-1,1,0,0};
    // int dy[4]={0,0,-1,1};
    // void dfs(int r,int c,vector<vector<char>>& board){
    //     int n=board.size();
    //     int m=board[0].size();
    //     board[r][c]='.';
    //     for(int i=0;i<4;i++){
    //         int nr=r+dx[i];
    //         int nc=c+dy[i];
    //         if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc]=='X'){
    //             dfs(nr,nc,board);
    //         }
    //     }
    // }

    int countBattleships(vector<vector<char>>& board) {
    
        int n=board.size();
        int m=board[0].size();
        int cnt=0;

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(board[i][j]=='X'){
        //             cnt++;
        //             dfs(i,j,board);
        //         }
        //     }
        // }

        // return cnt;

          /*
               .
            .  X      -> this should only be counted

               .
            X  X

               X
            .  X
            
          */

          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X'){
                    if(i==0 && j==0){
                        cnt++;
                    }else if(i==0){
                        if(board[i][j-1]!='X')
                            cnt++;
                    }else if(j==0 ){
                        if(board[i-1][j]!='X')
                            cnt++;
                    }else if(board[i-1][j]=='.' && board[i][j-1]=='.'){
                        cnt++;
                    }
                }
            }
          }
          return cnt;
    }
};