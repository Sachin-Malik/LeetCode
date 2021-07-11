class Solution {
public:
vector<vector<string> > res;
vector<vector<string> > partition(string s) {
        vector<string> temp;
        backtrack(0,"",s,temp);
        return res;
}
void backtrack(int index,string current,string&s,vector<string>&temp)
{
        if(index==s.length())
        {
                int l=0;
                for(auto s:temp)
                        l+=s.length();
                if(l==s.length())
                        res.push_back(temp);
                return;
        }
        current+=s[index];

        if(current.size()!=0&&is_palindrome(current)) {

                temp.push_back(current);
                backtrack(index+1,"",s,temp);
                temp.pop_back();

                backtrack(index+1,current,s,temp);
        }
        else{

                backtrack(index+1,current,s,temp);
        }
}
bool is_palindrome(string&s)
{
        int l=s.length();
        if(l==1)
                return true;
        for(int i=0; i<l/2; i++)
        {
                if(s[i]!=s[l-1-i])
                        return false;
        }
        return true;
}
};
