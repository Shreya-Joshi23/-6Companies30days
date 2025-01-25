class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        // perform n rotations
        /*          0 1 2 3
            nums = [4,3,2,6]
            0->25(0*4+1*3+2*2+3*6)
                3 0 1 2
            1->[6,4,3,2](16)(0*6+1*4+2*3+3*2)
        */

        long sum=0,fn=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            fn+=(i*nums[i]);
        }
        long l=1,r=l+n-1;
        long newfn=fn;

        while(l<n){
            r=l+n-1;
            long removed=(l-1)*nums[l-1];
            long added=r*nums[r%n];
            newfn=newfn-removed+added-sum;
            fn=max(fn,newfn);
            l++;
        }

        return (int)fn;
    }
};