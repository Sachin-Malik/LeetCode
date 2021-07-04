class Solution {
public:
unordered_map<string,int> in_dict;
map<pair<string,int>,bool> dp;
bool found=0;
bool wordBreak(string s, vector<string>& wordDict) {

        for(auto word:wordDict)
                in_dict[word]=1;
        return memo(0,"",s);

}
bool memo(int index,string current_str,string s ){

        if(found)
                return true;

        if(index==s.length()) {
                if(current_str.length()==0) {
                        found=1;
                        return true;
                }
                else
                        return false;
        }

        if(dp.find({current_str,index})!=dp.end())
                return dp[{current_str,index}];

        current_str+=s[index];
        if(in_dict[current_str]) {
                return dp[{current_str,index}]=memo(index+1,"",s)||memo(index+1,current_str,s);
        }
        else
                return dp[{current_str,index}]=memo(index+1,current_str,s);

}
};
