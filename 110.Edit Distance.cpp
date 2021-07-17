class Solution {
public:
int minDistance(string word1, string word2) {
        vector<vector<int> > res(word1.size()+1,vector<int>(word2.size()+1));

        for(int i=0; i<res.at(0).size(); i++)
                res[0][i]=i;
        for(int j=0; j<res.size(); j++)
                res[j][0]=j;

        for(int i=1; i<res.size(); i++)
        {
                for(int j=1; j<res.at(0).size(); j++)
                {
                        if(word1[i-1]==word2[j-1])
                                res[i][j]=res[i-1][j-1];
                        else
                                res[i][j]=1+min({res[i-1][j-1],res[i-1][j],res[i][j-1]});
                }
        }

        return res[res.size()-1][res.at(0).size()-1];
}
};
