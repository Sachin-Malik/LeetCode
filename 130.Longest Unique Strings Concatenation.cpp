class Solution {
public:
int maxUniqueChar(string s){
        int count[26] = {0};
        for(int i = 0; i < s.size(); i++)
                if(count[s[i] - 'a']++ > 0) return -1;

        return s.size();
}
void solve(vector<string>& arr, int index, string curr, vector<int>&ans){
        if(index == arr.size() && maxUniqueChar(curr) > ans[0]) {
                ans[0] = curr.size();
                return;
        }
        if(index == arr.size()) return;

        solve(arr, index+1, curr, ans);
        solve(arr, index+1, curr+arr[index], ans);
}
int maxLength(vector<string>& arr) {
        vector<int>ans(1);
        solve(arr, 0, "", ans);
        return ans[0];
}
};
