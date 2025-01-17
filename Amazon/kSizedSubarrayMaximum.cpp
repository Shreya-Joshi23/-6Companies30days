class Solution {
public:
    long long maximumSubarraySum(vector<int>& arr, int k) {
        int n=arr.size();
        // {element,index}
        map<int,int>mp;
        int left=0,right=0;
        long long sum=0;
        long long maxi=INT_MIN;
        while(right<n){
            int lastocc=mp.count(arr[right])?mp[arr[right]]:-1;
            while(lastocc>=left || right-left+1>k){
                sum-=arr[left];
                left++;
            }
            mp[arr[right]]=right;
            sum+=arr[right];
            if(right-left+1==k)
                maxi=max(maxi,sum);
            right++;
        }
        return maxi==INT_MIN?0:maxi;
    }
};