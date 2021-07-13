class Solution {
public:
bool found=false;
bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0; i<nums.size(); i++)
                sum+=nums[i];
        if(sum%k)
                return false;
        int target=sum/k;
        vector<int> visited(nums.size(),false );
        return backtrack(0,0,target,k,nums,visited);

}
bool backtrack(int index,int current_sum,int &target,int k,vector<int>&nums,vector<int>&visited)
{
        if(k==1)
                return true;

        if(current_sum==target)
                return backtrack(0,0,target,k-1,nums,visited); //start searching again

        for(int i=index; i<nums.size(); i++)
        {
                if(visited[i]||current_sum+nums[i]>target)
                        continue;

                visited[i]=true;
                bool res=backtrack(i+1,current_sum+nums[i],target,k,nums,visited);
                if(res) return true;
                visited[i]=false;

        }
        return false;
}
};
