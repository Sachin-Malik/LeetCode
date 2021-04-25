//Ques No. 120
//Given a triangle array, return the minimum path sum from top to bottom.

//For each step, you may move to an adjacent number of the row below. More formally,
//if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.


class Solution {
public:
int minimumTotal(vector<vector<int> >& triangle) {
        //traverse the triangle in depth-first order and updates sums;
        int size = triangle.size();
        for(int i=size-2; i>=0; i--)
                for(int j=0; j<triangle[i].size(); j++)
                        triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);

        return triangle[0][0];
}
};
