class Solution {
public:
vector<vector<int> > res;
vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        recursive(0,target,temp,candidates);
        return res;

}
void recursive(int index,int target,vector<int>&temp,vector<int>&nums)
{
        if(index==nums.size())
                return;

        if(target<0)
                return;

        if(target==0) {
                res.push_back(temp);
                return;
        }
        recursive(index+1,target,temp,nums);
        temp.push_back(nums[index]);
        recursive(index,target-nums[index],temp,nums);
        temp.pop_back();
        return;
}
};
