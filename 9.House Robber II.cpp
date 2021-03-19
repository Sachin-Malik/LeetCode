// You are a professional robber planning to rob houses along a street.
// Each house has a certain amount of money stashed. All houses at this place are arranged in a circle.
// That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security
// system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
//
// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can
// rob tonight without alerting the police.


class Solution {
public:
int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
                return 0;
        if(n==1)
                return nums[0];
        if(n==2)
                return max(nums[0],nums[1]);

        if(n==3)
                return max(nums[2],max(nums[0],nums[1]));

        vector<int> vtr1,vtr2;
        for(int i=0; i<n-1; i++)
                vtr1.push_back(nums[i]);
        for(int i=1; i<n; i++)
                vtr2.push_back(nums[i]);


        vector<int> res1(vtr1.size());
        res1[0]=vtr1[0];
        res1[1]=max(vtr1[0],vtr1[1]);
        for(int i=2; i<vtr1.size(); i++)
        {
                res1[i]=max(res1[i-1],res1[i-2]+vtr1[i]);
        }
        int max1=res1[vtr1.size()-1];

        vector<int> res2(vtr2.size());
        res2[0]=vtr2[0];
        res2[1]=max(vtr2[0],vtr2[1]);
        for(int i=2; i<vtr2.size(); i++)
                res2[i]=max(res2[i-1],res2[i-2]+vtr2[i]);

        return max(res1[vtr1.size()-1],res2[vtr2.size()-1]);

}
};
