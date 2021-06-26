class Solution {
public:
vector<vector<int> > res;
vector<vector<int> > permute(vector<int>& nums) {
        int index=0;
        backtrack(index,nums);
        return res;
}
void backtrack(int index,vector<int>&nums)
{
        if(index==nums.size()-1)
        {
                res.push_back(nums);
                return;
        }
        for(int i=index; i<nums.size(); i++)
        {
                swap(nums[index],nums[i]);
                backtrack(index+1,nums);
                swap(nums[index],nums[i]);
        }
}
};
