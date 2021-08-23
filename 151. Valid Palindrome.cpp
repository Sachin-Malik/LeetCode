class Solution {
public:
bool validPalindrome(string s) {
        int n=s.length();
        int l=0,r=n-1;
        while(l<=r) {
                if(s[l]!=s[r])
                        break;
                else
                        l++,r--;
        }

        if(l>r) return true;
        if(is_palindrome(l+1,r,s)) return true;
        if(is_palindrome(l,r-1,s)) return true;
        return false;
}

bool is_palindrome(int l,int r,string &s){
        while(l<=r) {
                if(s[l++]!=s[r--])
                        return false;
        }
        return true;
}
};
