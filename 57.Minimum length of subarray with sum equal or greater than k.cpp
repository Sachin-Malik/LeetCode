class Solution {
public:
int minSubArrayLen(int target, vector<int>& nums) {
        int min_length=INT_MAX,sum=0,n=nums.size();
        int p1=0,p2=0;
        while(p1<n)
        {
                sum+=nums[p1];
                p1++;
                while(sum>=target&&p2<=p1)
                {
                        if(p2==p1)
                                return 1;
                        min_length=min(min_length,p1-p2);
                        sum-=nums[p2];
                        p2++;
                }
        }
        if(min_length==INT_MAX)
                return 0;
        return min_length;

}
};
