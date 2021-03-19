// Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.
// The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.
// You may assume the integer does not contain any leading zero, except the number 0 itself.

// Time -> O(n) || Space -> O(1) for Best Case && O(n) for Worst Case

class Solution {
public:
vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        vector<int> res;
        int carry=0;
        if(digits[n-1]==9)
        {
                digits[n-1]=0;
                carry=1;
        }
        else
                digits[n-1]++;

        for(int i=n-2; i>=0; i--)
        {
                if(digits[i]+carry==10)
                {
                        digits[i]=0;
                        carry=1;
                }
                else
                {
                        digits[i]=digits[i]+carry;
                        carry=0;
                }

        }
        if(carry==1)
        {
                res.push_back(1);
                for(int i=0; i<n; i++)
                        res.push_back(digits[i]);
                return res;
        }

        else
                return digits;
}
};
