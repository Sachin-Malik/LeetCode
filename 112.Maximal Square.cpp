class Solution {
public:
int maximalSquare(vector<vector<char> >& matrix) {
        vector<vector<int> > res(matrix.size(),vector<int>(matrix.at(0).size(),0));
        int min_area=0;

        for(int i=0; i<res.size(); i++)
                res[i][0]=matrix[i][0]-'0';
        for(int j=0; j<res.at(0).size(); j++)
                res[0][j]=matrix[0][j]-'0';

        for(int i=1; i<res.size(); i++) {
                for(int j=1; j<res.at(0).size(); j++) {
                        if(matrix[i][j]-'0'!=0) {
                                res[i][j]=1+min({res[i-1][j],res[i][j-1],res[i-1][j-1]});
                        }
                }
        }

        for(int i=0; i<res.size(); i++) {
                for(int j=0; j<res.at(0).size(); j++) {
                        min_area=max(min_area,res[i][j]);
                }
        }
        return min_area*min_area;
}
};
