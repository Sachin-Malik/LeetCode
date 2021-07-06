class Solution {
public:
int total_solutions=0;
vector<vector<int> > res;
int countArrangement(int n) {

        vector<int> nums;
        nums.push_back(0);
        for(int i=1; i<=n; i++)
                nums.push_back(i);
        backtrack(1,nums);
        return total_solutions;

}
void backtrack(int index,vector<int>&nums)
{
        if(index==nums.size()) {
                total_solutions++;
                return;
        }

        for(int i=index; i<nums.size(); i++)
        {
                swap(nums[index],nums[i]);
                if((index%nums[index]==0||nums[index]%index==0)) {
                        backtrack(index+1,nums);
                }
                swap(nums[index],nums[i]);
        }
        return;
}
};
class Solution {
public:
int total_solutions=0;
vector<vector<int> > res;
int countArrangement(int n) {

        vector<int> nums;
        nums.push_back(0);
        for(int i=1; i<=n; i++)
                nums.push_back(i);
        backtrack(1,nums);
        return total_solutions;

}
void backtrack(int index,vector<int>&nums)
{
        if(index==nums.size()) {
                total_solutions++;
                return;
        }

        for(int i=index; i<nums.size(); i++)
        {
                swap(nums[index],nums[i]);
                if((index%nums[index]==0||nums[index]%index==0)) {
                        backtrack(index+1,nums);
                }
                swap(nums[index],nums[i]);
        }
        return;
}
};
