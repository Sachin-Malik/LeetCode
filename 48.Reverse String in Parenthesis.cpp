// You are given a string s that consists of lower case English letters and brackets.
// Reverse the strings in each pair of matching parentheses, starting from the innermost one.
// Your result should not contain any brackets.

class Solution {
public:
string reverseParentheses(string s) {
        stack<int>st;
        for(int i=0; i<s.length(); i++)
        {

                if(s[i]=='(') {
                        st.push(i);
                }
                else if(s[i]==')') {
                        int left=st.top(); st.pop();

                        int right=i-1;
                        while(left<=right) {
                                swap(s[left],s[right]);
                                left++; right--;
                        }

                }


        }
        string ans="";
        for(int i=0; i<s.length(); i++) {
                if(s[i]!=')'&&s[i]!='(') {
                        ans+=s[i];
                }
        }
        return ans;

}
};
