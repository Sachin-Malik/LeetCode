class Solution {
public:
int countSubstrings(string s) {
        int str_len=s.length(),palindromic_substring=0;

        //for odd length palindromes
        int l,r;
        for(int i=0; i<str_len; i++) {
                l=i,r=i;
                while(l>=0&&r<str_len&&s[l]==s[r]) {
                        palindromic_substring++;
                        l--;
                        r++;
                }
        }

        //for even length palindromes
        for(int i=0; i<str_len-1; i++) {
                l=i,r=i+1;
                while(l>=0&&r<str_len&&s[l]==s[r]) {
                        palindromic_substring++;
                        l--;
                        r++;
                }
        }
        return palindromic_substring;
}
};
