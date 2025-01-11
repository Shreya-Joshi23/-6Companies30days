class Solution {
public:
    map<int,vector<int>>mp;
    int total_area=0;
    Solution(vector<vector<int>>& rects) {
        int n=rects.size();
        for(auto rect:rects){
            int area=(rect[2]-rect[0]+1)*(rect[3]-rect[1]+1);
            total_area+=area;
            mp[total_area]=rect;
        }
    }
    
    vector<int> pick() {
        //random rectangle
        int r=rand()%total_area;
        auto temp=mp.upper_bound(r);
        vector<int>z=temp->second;
        int x=z[0]+rand()%(z[2]-z[0]+1);
        int y=z[1]+rand()%(z[3]-z[1]+1);
        return {x,y};
    }
};
