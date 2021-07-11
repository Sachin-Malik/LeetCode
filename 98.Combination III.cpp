class Solution {
public:
vector<vector<int> > res;
vector<vector<int> > combinationSum3(int k, int n) {

        vector<int>nums;
        backtrack(n,k,9,nums);
        return res;

}
void backtrack(int n,int count,int index,vector<int>&nums)
{
        if(n==0&&count==0)
        {
                res.push_back(nums);
                return;
        }

        if(index==0)
                return;

        if(count==0||n==0)
                return;

        if(n-index>=0)
        {
                nums.push_back(index);
                backtrack(n-index,count-1,index-1,nums);
                nums.pop_back();

                backtrack(n,count,index-1,nums);
        }
        else
                backtrack(n,count,index-1,nums);

}
};
