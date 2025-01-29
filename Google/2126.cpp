class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& ast) {
        int n=ast.size();
        sort(ast.begin(),ast.end());
        long long m=mass;
        for(int i=0;i<n;i++){
            if(m>=ast[i]){
                m+=ast[i];
                cout<<mass<<endl;
            }else{
                return false;
            }
        }
        return true;
    }
};