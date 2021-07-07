class Solution {
public:
vector<string> res;
vector<string> letterCasePermutation(string s) {
        backtrack(0,s);
        return res;
}
void backtrack(int index,string &s)
{
        if(index==s.length()) {
                res.push_back(s);
                return;
        }

        if(isalpha(s[index])) {//is isalpha then we can either change the case(lower to upper or vice-a-versa) or we don't

                //don't change
                backtrack(index+1,s);
                //change case
                change_case(index,s);
                backtrack(index+1,s);
                change_case(index,s);

        }
        else //we can't change have to proceed
                backtrack(index+1,s);

        return;
}
void change_case(int index,string & input)
{
        if(isupper(input[index])) {
                char l=tolower(input[index]);
                input[index]=l;
        }
        else{
                char u=toupper(input[index]);
                input[index]=u;
        }
}
};
