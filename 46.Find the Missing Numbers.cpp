class Solution {
public:
vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;

        for( int i=0; i < nums.size(); i++)
        {
                int n = abs(nums[i]);
                if(nums[n-1] > 0)
                        nums[n-1] = -nums[n-1]; // marking -ve
        }
        for( int i=0; i < nums.size(); i++)
        {
                if(nums[i]>0)
                        res.push_back(i+1);
        }
        return res;
}
};
