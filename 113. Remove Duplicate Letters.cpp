class Solution {
public:
string removeDuplicateLetters(string s) {

        int n = s.size();

        map<char,int> countChar;
        countChar.clear();

        for(auto &ch : s) countChar[ch]++;
        map<char,bool> vis;
        vis.clear();

        stack<char> st;
        st.push(s[0]);
        vis[s[0]] = true;
        countChar[s[0]]--;

        for(int i=1; i<n; i++) {
                if(vis[s[i]] == false) {
                        while(!st.empty() && (st.top() > s[i]) && (countChar[st.top()]>0)) {
                                vis[st.top()] = false;
                                st.pop();
                        }
                        st.push(s[i]);
                        vis[s[i]] = true;
                }
                countChar[s[i]]--;
        }

        string ans = "";
        while(!st.empty()) {
                ans += st.top();
                st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;

}
};
