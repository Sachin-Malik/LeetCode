class Solution {
public:
string getSmallestString(int n, int k) {
        int cap=26*n;
        string res="";
        while(cap-26>=k-1)
        {
                res+='a';
                cap=cap-26;
                k--;
        }
        string temp="";
        while(k>=26&&cap-26>=0)
        {
                temp+='z';
                k-=26;
                cap-=26;
        }
        if(k>0)
                temp+='a'+k-1;
        reverse(temp.begin(),temp.end());
        res+=temp;
        return res;

}
};
