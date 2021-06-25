class Solution {
public:
vector<int> majorityElement(vector<int>& nums) {
        //moore's voting Algo
        int N = nums.size();
        int count1 = 0, count2= 0, major1= INT_MAX, major2 = INT_MAX;
        int req=nums.size()/3;
        for(int i=0; i<nums.size(); i++)
        {
                if(nums[i]==major1)
                        count1++;

                else if(nums[i]==major2)
                        count2++;

                else if(count1==0) {
                        major1=nums[i];
                        count1=1;
                }
                else if(count2==0) {
                        count2=1;
                        major2=nums[i];
                }
                else {
                        count1--;
                        count2--;
                }
        }
        count1=0,count2=0;
        for(int i=0; i<nums.size(); i++)
        {
                if(nums[i]==major1)
                        count1++;
                if(nums[i]==major2)
                        count2++;
        }
        if(count1>req&&count2>req)
                return {major1,major2};
        if(count1>req)
                return {major1};
        if(count2>req)
                return {major2};
        return {};
}
};
