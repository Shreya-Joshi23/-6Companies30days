class TrieNode{
    public:
    unordered_map<char,TrieNode*>children;
    bool is_word;
};

class Solution {
public:
    /* Time Complexity->O(N^3)*/
        //O(n)
    int solve(int start,string s, TrieNode* root,vector<int>&dp){
        int n=s.size();
        if(start>=n)return 0;
        if(dp[start]!=-1)return dp[start];
        //consider character at start as extra character
        int ans=1+solve(start+1,s,root,dp);
        //consider character at start as not extra character
        TrieNode* node=root;
        for(int end=start;end<n;end++){//O(n)
            char ch=s[end];
            if(node->children.find(ch)==node->children.end()){
                break;
            }
            node=node->children[ch];
            if(node->is_word){
                ans=min(ans,solve(end+1,s,root,dp));
            }
        }
        return dp[start]=ans;
    }

    TrieNode* buildTrie(vector<string>&dict){
        auto root=new TrieNode();
        for(auto &word:dict){
            auto node=root;
            for(auto &ch:word){
                if(node->children.find(ch)==node->children.end()){
                    node->children[ch]=new TrieNode();
                }
                node=node->children[ch];
            }
            node->is_word=true;
        }
        return root;
    }

    int minExtraChar(string s, vector<string>& dict) {
        /*
            s = "leetscode", dictionary = ["leet","code","leetcode"]
            how many minimum substrings are not found in dict
            for a character in s we have 2 options either it is an extra character or it forms a string which is a part of dict
        */

        int n=s.size();
        vector<int>dp(n,-1);
        auto root=buildTrie(dict);
        unordered_set<string>st(dict.begin(),dict.end());
        return solve(0,s,root,dp);

    }
};