class Solution {
public:
bool sumGame(string nums) {
        int sum=0,count=0,n=nums.length();
        for(int i=0; i<n; i++) {
                if(i<n/2) {
                        if(nums[i]=='?')
                                count++;
                        else
                                sum+=nums[i]-'0';
                }else{
                        if(nums[i]=='?')
                                count--;
                        else
                                sum-=nums[i]-'0';
                }
        }
        if(count%2)
                return true;

        if(sum==-(count/2)*9)
                return false;
        return true;
}
};
