class Solution {
public:
vector<string> res;
vector<string> restoreIpAddresses(string s) {
        int count=0,dots=0;
        string current="";
        backtrack(0,1,count,dots,current,s);
        return res;
}
void backtrack(int index,int val,int count,int dots,string&current,string &s){

        if(index==s.length()) {
                if(dots==3)
                        res.push_back(current);
                return;
        }

        if(dots>3)
                return;

        //we have to put a dot here. if we have include 3 digits
        if(count==3) {
                current.push_back('.');
                if(val<=255)
                        backtrack(index,0,0,dots+1,current,s);
                current.pop_back();
                return;
        }

        //we have to include this char (there are not digits in current section)
        if(count==0) {
                current.push_back(s[index]);
                val=s[index]-'0';
                backtrack(index+1,val,count+1,dots,current,s);
                current.pop_back();
                return;
        }

        //avoid leading zero.
        if(count==1&&current[current.length()-1]=='0') {
                current.push_back('.');
                backtrack(index,val,0,dots+1,current,s);
                current.pop_back();
                return;
        }

        current.push_back('.');
        backtrack(index,0,0,dots+1,current,s);
        current.pop_back();

        current.push_back(s[index]);
        val=(val*10)+s[index]-'0';
        if(val<=255)
                backtrack(index+1,val,count+1,dots,current,s);
        val=val/10;
        current.pop_back();

        return;
}
};
