class Solution {
public:
int countPalindromicSubsequence(string s) {
        vector<pair<int,int> > first_and_last(26,{-1,-1});

        int l=s.length();


        for(int i=0; i<l; i++) {
                if(first_and_last[s[i]-'a'].first==-1)
                        first_and_last[s[i]-'a'].first=i;
                first_and_last[s[i]-'a'].second=i;
        }

        int pali_seq=0;
        unordered_map<char,int> freq;
        for(int i=0; i<26; i++) {
                freq.clear();
                for(int j=first_and_last[i].first+1; j<first_and_last[i].second&&j<l; j++) {
                        freq[s[j]]++;
                }
                pali_seq+=freq.size();
        }
        return pali_seq;
}
};
