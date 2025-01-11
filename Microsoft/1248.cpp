class Solution {
public:

    int subarrayslessthanequaltok(vector<int>&nums,int k){
        int n=nums.size();
        int i=0,j=0;

        int sum=0;
        int cnt=0;

        while(j<n){
            sum+=nums[j];
            while(i<n && sum>k){
                sum-=nums[i++];
            }
            cnt+=(j-i+1);
            j++;
        }

        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        /*
            nums = [2,2,2,1,2,2,1,2,2,2]
                   [0,0,0,1,0,0,1,0,0,0]
        */

        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2){
                nums[i]=1;
            }else{
                nums[i]=0;
            }
        }

        return (subarrayslessthanequaltok(nums,k)-subarrayslessthanequaltok(nums,k-1));
    }
};