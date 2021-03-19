
// Given a signed 32-bit integer x, return x with its digits reversed.
//If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.



class Solution {
public:
int reverse(int x) {
        long long reverse=0;
        int i=0;
        int rem=0;
        int div=0;
        while(x>0)
        {
                rem=x%10;
                reverse=reverse*10+rem;
                x=x/10;
                i++;
        }
        if(reverse>INT_MAX||reverse<INT_MIN)
                return 0;
        return reverse;
}
};
