class Solution {
public:
int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size(),p1=0,p2=1,p3=n-1,sum=INT_MAX,minDiff=INT_MAX, res_sum=INT_MAX;
        sort(nums.begin(),nums.end());
        while(p1<n-2)
        {
                p2=p1+1;
                p3=n-1;
                while(p2<p3) {
                        sum=nums[p1]+nums[p2]+nums[p3];
                        if(abs(sum-target)<=minDiff)
                        {
                                minDiff=abs(sum-target);
                                res_sum=sum;
                        }
                        if(minDiff==0)
                                return res_sum;
                        if(sum>target)
                                p3--;
                        else
                                p2++;
                }
                p1++;
        }
        return res_sum;
}
};
