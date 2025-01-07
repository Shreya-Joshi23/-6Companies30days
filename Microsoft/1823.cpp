class Solution {
public:
    int WinnerHelper(int n,int k){
        if(n==1)return 0;
        return (WinnerHelper(n-1,k)+k)%n;
    }

    int findTheWinner(int n, int k) {
        return (WinnerHelper(n,k)+1);
    }
};