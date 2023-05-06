class Solution {
public:
    int MOD = 1e9+7;
    long long helper(int number, int powerRaised){
        if(number==0 || powerRaised==0) return 1;
        if(powerRaised==1) return number;
        long long ans=1;
        if(powerRaised%2==0){
            ans=helper(number,powerRaised/2);
            ans*=ans;
            ans%=MOD;
        }else{
            ans=helper(number,powerRaised-1);
            ans*=number;
            ans%=MOD;
        }
    return ans%MOD;
    }

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int start=0,end=nums.size()-1;
        long long ans=0;
        while(start<=end){
            if(nums[start]+nums[end]<=target){
                ans+=helper(2,end-start);
                ans%=MOD;
                start++;
            }else{
                end--;
            }
        }
        return ans%MOD;
    }
};