// Given a string containing digits from 2-9 inclusive, return all possible letter
// combinations that the number could represent. Return the answer in any order.
//
// A mapping of digit to letters (just like on the telephone buttons) is given below.
// Note that 1 does not map to any letters.
class Solution {
public:
vector<string> letterCombinations(string digits) {
        vector<string> res;

        if(digits.length()==0)
                return {};
        unordered_map<int,string> umap;
        umap[2]="abc";
        umap[3]="def";
        umap[4]="ghi";
        umap[5]="jkl";
        umap[6]="mno";
        umap[7]="pqrs";
        umap[8]="tuv";
        umap[9]="wxyz";
        int digLength=digits.length();
        // reverse(digits.begin(),digits.end());
        string current;
        helper(current,0,res,digLength,umap,digits);
        return res;


}
void helper(string current, int pos,vector<string>&res,int &digLength,unordered_map<int,string> &umap,string &digits)
{
        for(int i=pos; i<=digLength; i++)
        {
                if(i==digLength)
                {
                        if(current.length()==digLength)
                                res.push_back(current);
                }
                else if(i<digLength)
                {
                        for(int j=0; j<umap[digits[i]-'0'].length(); j++)
                        {
                                helper(current+umap[digits[i]-'0'][j],i+1,res,digLength,umap,digits);
                        }
                }
                else
                {
                        return;
                }
        }
}

};
