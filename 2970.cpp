class Solution
{
public:
    int incremovableSubarrayCount(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                int l = -1, flag = 1;
                for (int k = 0; k < nums.size(); k++)
                {
                    if (k >= i && k <= j)
                        continue;
                    if (l >= nums[k])
                    {
                        flag = 0;
                        break;
                    }
                    l = nums[k];
                }
                if (flag)
                    ans++;
            }
        }
        return ans;
    }
};