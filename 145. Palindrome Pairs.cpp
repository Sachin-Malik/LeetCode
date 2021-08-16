class Solution {
public:
vector<vector<int> > palindromePairs(vector<string>& words) {
        vector<vector<int> > result;
        unordered_map<string, int> dict;
        int i, j, size = words.size();
        string left, right, tmp;
        for(i = 0; i < size; i++) {
                tmp = words[i];
                reverse(tmp.begin(), tmp.end());
                dict[tmp] = i;
        }

        for(i = 0; i < size; i++) {
                for(j = 0; j < words[i].size(); j++) {
                        left = words[i].substr(0, j);
                        right = words[i].substr(j);
                        if(dict.find(left) != dict.end() && dict[left] != i && isPalindrome(right)) {
                                result.push_back({i, dict[left]});
                                if(left.empty())
                                        result.push_back({dict[left], i});
                        }
                        if(dict.find(right) != dict.end() && dict[right] != i && isPalindrome(left))
                                result.push_back({dict[right], i});
                }
        }
        return result;
}

private:
bool isPalindrome(string s) {
        int start, end, size = s.size();
        for(start = 0, end = size - 1; start < end; start++, end--) {
                if(s[start] != s[end])
                        return false;
        }
        return true;
}
};
