// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        
        /*
        {"geeikistest", "geeksforgeeks", "geeksfortest"}
        s="geeips"
        mp=[
            g->"geeikistest"
            ge->geeikistest
            gee->geeikistest
        */
        
        int m=s.size();
        
        vector<vector<string>>v(m,vector<string>());
        
        sort(contact,contact+n);
        for(int i=0;i<n;i++){
            // may contain duplicate strings
            if(i>0 && contact[i]==contact[i-1])continue;
            int j=0;
            while(j<m && j<contact[i].size() && contact[i][j]==s[j]){
                v[j].push_back(contact[i]);
                j++;
            }
        }
        
        for(int i=0;i<m;i++){
            if(v[i].empty())
                v[i].push_back("0");
        }
        
        // for(int i=0;i<v.size();i++){
        //     for(auto it:v[i]){
        //         cout<<it<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return v;
    }
};