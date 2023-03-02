class Solution {
public:
    int compress(vector<char>& chars) {
        char last = chars[0];
        int i = 1, j = 1;
        int group = 1;
        for (; j < chars.size(); ++j){
            if (chars[j] == last){
                group++;
            } else {
                if (group > 1){
                    string s = to_string(group);
                    for (int k = 0; k < s.length(); ++k){
                        chars[i++] = s[k];
                    }
                }
                group = 1;
                last = chars[j];
                chars[i++] = chars[j];
            }
        }
        if (group > 1){
            string s = to_string(group);
            for (int k = 0; k < s.length(); ++k){
                chars[i++] = s[k];
            }
        }
        return i;
        
    }
};