/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void creategraph(TreeNode* root,map<int,vector<int>>&mp,TreeNode* parent){
        if(root==NULL)return;
        if(parent->val!=-1){
            mp[root->val].push_back(parent->val);
            mp[parent->val].push_back(root->val);    
        }
        creategraph(root->left,mp,root); 
        creategraph(root->right,mp,root);
    }

    // int maxlevel=0;
    // void dfs(int start,map<int,vector<int>>&mp,int level,set<int>&visited){
    //     if(mp[start].empty())return;
    //     visited.insert(start);
    //     maxlevel=max(maxlevel,level);
    //     for(auto it:mp[start]){
    //         if(visited.find(it)==visited.end())
    //             dfs(it,mp,level+1,visited);
    //     }
    // }

    int amountOfTime(TreeNode* root, int start) {
        /*
            1->[5,3]
            5->[4]
            3->[1,10,6]
            4->[9,2]
            9->[]
            2->[]
            10->[]
            6->[]

            level=4
            Q->{}

            visitedset
                          dfs(3,0)
                dfs(10,1)   (6,1)   (1,1)
                                (5,2)
                                (4,3)
                            (9,4)   (2,4)
        */

        map<int,vector<int>>mp;
        creategraph(root,mp,new TreeNode(-1));

        // cout<<"Graph"<<endl;
        // for(auto it:mp){
        //     cout<<it.first<<" ";
        //     for(auto ele:it.second){
        //         cout<<ele<<" ";
        //     }
        //     cout<<endl;
        // }

        set<int>visited;
        // dfs(start,mp,0,visited);
        // return maxlevel;

        queue<int>q;
        q.push(start);
        visited.insert(start);
        int maxlevel=-1;

        while(!q.empty()){
            int size=q.size();
            maxlevel++;
            while(size--){
                int top=q.front();
                q.pop();
                for(auto it:mp[top]){
                    if(visited.find(it)==visited.end()){
                        q.push(it);
                        visited.insert(it);
                    }
                }
            }
        }

        return maxlevel;
    }
};