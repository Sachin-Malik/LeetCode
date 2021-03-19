


// Given an unsorted integer array nums, find the smallest missing positive integer.


class Solution {
public:
int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        bool has_one=false;
        for(int i=0; i<n; i++)
                if(nums[i]==1)
                {
                        has_one=true;
                        break;
                }

        if(!has_one)
                return 1;

        if(n==1)
                return 2;

        for(int i=0; i<n; i++)
        {
                if(nums[i]<=0||nums[i]>n)
                        nums[i]=1;
        }

        for(int i=0; i<n; i++)
        {
                if(nums[abs(nums[i])-1]>0)
                {
                        nums[abs(nums[i])-1]*=-1;
                }
        }

        for(int i=0; i<n; i++)
        {
                if(nums[i]>0)
                        return i+1;
        }
        return n+1;
}
};
