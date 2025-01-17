class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        /*
            nums = [1,5,1,1,6,4]
            [1,1,1,4,5,6]
            [1,6,1,5,1,4]
            nums = [1,3,2,2,3,1]
            [1,1,2,2,3,3]
            [2,3,1,3,1,2]
        */
        priority_queue<int,vector<int>>pq(nums.begin(),nums.end());

        int n=nums.size();
        for(int i=1;i<n;i+=2){
            nums[i]=pq.top();
            pq.pop();
        }

        for(int i=0;i<n;i+=2){
            nums[i]=pq.top();
            pq.pop();
        }

    }
};