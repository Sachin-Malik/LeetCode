class Solution {
public:
int max_splits=0,current_splits=0;
unordered_map<string,int> is_included;
int maxUniqueSplit(string s) {
        string current="";
        backtrack(0,s,current);
        return max_splits;
}
void backtrack(int index,string&s,string current)
{

        if(index==s.length()) {

                max_splits=max(max_splits,current_splits);
                return;
        }

        current+=s[index];
        if(!is_included[current])
        {
                backtrack(index+1,s,current);

                current_splits++;
                is_included[current]=1;
                backtrack(index+1,s,"");
                current_splits--;
                is_included.erase(current);
        }
        else{

                backtrack(index+1,s,current);
        }
}
};
