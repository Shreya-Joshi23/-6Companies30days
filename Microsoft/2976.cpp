class Solution {
public:

    int INF=1e9;

    vector<long long> dijakstra(char start,int vertices,vector<vector<pair<char,int>>>&adjList){
        priority_queue<pair<long long,char>,vector<pair<long long,char>>,greater<pair<long long,char>>>pq;
        vector<long long>dist(vertices,INF);
        pq.push({0,start});
        dist[start-'a']=0;

        while(!pq.empty()){
            char u=pq.top().second;
            char udist=pq.top().first;
            pq.pop();

            for(const auto &it:adjList[u-'a']){
                char v=it.first;
                int weight=it.second;

                if(dist[u-'a']+weight<dist[v-'a']){
                    dist[v-'a']=dist[u-'a']+weight;
                    pq.push({dist[v-'a'],v});
                }
            }
        }
        return dist;
    }

    long long minimumCost(string s, string t, vector<char>& org, vector<char>& ch, vector<int>& cost) {
        long long res=0;
        int n=s.size();
        int n1=org.size();
        vector<vector<pair<char,int>>>adj(26);

        for(int i=0;i<n1;i++){
            adj[org[i]-'a'].push_back({ch[i],cost[i]});
        }

        vector<vector<long long>>d;
        for(char i='a';i<='z';i++){
            vector<long long>temp=dijakstra(i,26,adj);
            d.push_back(temp);
        }

        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                long long gg=d[s[i]-'a'][t[i]-'a'];
                if(gg==INF)return -1;
                res+=gg;
            }
        }

        return res;
    }
};