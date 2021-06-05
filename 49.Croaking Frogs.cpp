class Solution {
public:
int maxFrogs=INT_MIN;
int minNumberOfFrogs(string s) {
        map<char,int> count;
        int n=s.length();

        count['c']=0,count['r']=0,count['o']=0,count['a']=0,count['k']=0;

        map<char,char> relation;
        relation['c']='c',relation['r']='c',relation['o']='r',relation['a']='r',relation['k']='a';

        for(int i=0; i<n; i++)
        {
                count[s[i]]++;

                if(s[i]!='c') {
                        if(count[s[i]]>count[relation[s[i]]])
                                return -1;
                }
                if(s[i]=='k') {
                        for(auto i:count)
                                maxFrogs=max(maxFrogs,count[i.first]--);
                }
        }
        for(auto i:count)
                if(i.second>0)
                        return -1;
        return maxFrogs;
}

};
