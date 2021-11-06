// Assume arrk to be an array obtained by rotating nums by k positions clock-wise.
// We define the rotation function F on nums as follow:
// F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].
// Find max F(k)

class Solution {
public:
int maxRotateFunction(vector<int>& nums) {
        int totalSum=0,n=nums.size(),maxSum=0,product=0,temp;

        for(int i=0; i<n; i++) {
                totalSum+=nums[i];
                product+=i*(nums[i]);
        }
        maxSum=product;
        for(int i=n-1; i>0; i--) {
                temp=product-(nums[i]*(n-1))+(totalSum-nums[i]);
                maxSum=max(maxSum,temp);
                product=temp;
        }
        return maxSum;
}
};
