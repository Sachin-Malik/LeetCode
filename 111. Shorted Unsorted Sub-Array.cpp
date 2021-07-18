class Solution {
public:
int findUnsortedSubarray(vector<int>& nums) {

        vector<int>v(nums.begin(),nums.end());
        sort(v.begin(),v.end());
        int l=0,r=0,f=0;

        for(int i=0; i<nums.size(); i++)
        {
                if(nums[i]!=v[i])
                {
                        f++;
                        l=i;
                        break;
                }
        }
        for(int i=nums.size()-1; i>=0; i--)
        {
                if(nums[i]!=v[i])
                {
                        r=i;
                        break;
                }
        }
        if(f==0)
                return 0;
        return (r-l+1);
}
};
