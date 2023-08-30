/*
    You are given a 0-indexed integer array nums. In one operation you can replace any element of the array with any two elements that sum to it.
    For example, consider nums = [5,6,7]. In one operation, we can replace nums[1] with 2 and 4 and convert nums to [5,2,4,7].
    Return the minimum number of operations to make an array that is sorted in non-decreasing order.
*/

class Solution
{
public:
    long long minimumReplacement(vector<int> &nums)
    {
        long long steps = 0;
        int n = nums.size();
        int largestUse = nums[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            int current = nums[i];
            long long nTimes = (current + largestUse - 1) / largestUse;
            steps += nTimes - 1;
            largestUse = current / nTimes;
        }
        return steps;
    }
};