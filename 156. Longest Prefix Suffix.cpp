class Solution {
public:
string longestPrefix(string s) {

        string str = s;
        reverse(str.begin(),str.end());
        string temp = s;

        int len = temp.length();
        vector<int>lps(len,0);
        int i=0,j=1;
        while( j < len)
        {
                if(temp[i] == temp[j])
                {
                        lps[j] = i+1;
                        i++;
                }
                else
                {
                        while(i > 0 && temp[i] != temp[j])
                                i = lps[i-1];

                        if(temp[i] != temp[j])
                                lps[j] = 0;

                        else
                        {
                                lps[j] = i+1;
                                i++;
                        }
                }
                j++;
        }
        return s.substr(0,lps[len-1]);
}
};
