// Given a string s, find the length of the longest substring without repeating characters.

class Solution {
public:
int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        int map[256] = {0};
        int n = s.length();
        int start = 0;
        int max_len = INT_MIN;
        for(int i=0; i<n; ++i) {
                map[s[i]]++;
                if(map[s[i]] > 1) {
                        max_len = max(max_len, (i - start));
                        while(s[start] != s[i]) {
                                map[s[start]]--;
                                start++;
                        }
                        map[s[start]]--;
                        start++;
                }
        }
        max_len = max(max_len, (n - start));
        if(start == 0) return n;
        else return max_len;
}
};
