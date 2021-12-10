/*
You have two robots that can collect cherries for you, Robot #1 is located at the top-left corner (0,0) , 
and Robot #2 is located at the top-right corner (0, cols-1) of the grid.

From a cell (i,j), robots can move to cell (i+1, j-1) , (i+1, j) or (i+1, j+1).
*/


class Solution {
public:
    int dp[70][70][70];
    vector<int> offsets={-1,1,0};
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
       return check(0,0,grid.at(0).size()-1,grid);
    }
    
    int check(int r,int c1,int c2,vector<vector<int>>&grid){
        
        int row=grid.size(),cols=grid.at(0).size();
        
        if(c1<0||c1>=cols||c2<0||c2>=cols)
            return INT_MIN;
        
        if(dp[r][c1][c2]!=-1)
            return dp[r][c1][c2];
        
        if(r==row-1){
            if(c1==c2){
                return grid[r][c1];
            }
            return grid[r][c1]+grid[r][c2];
        }
        
        int temp=0;
        if(c1==c2){
            temp=grid[r][c1];
        }else{
            temp=grid[r][c1]+grid[r][c2];
        }
        
        int m=INT_MIN;
        for(int i=0;i<offsets.size();i++){
            for(int j=0;j<offsets.size();j++){
                m=max(m,check(r+1,c1-offsets[i],c2-offsets[j],grid));
            }
        }
        temp+=m;
        return dp[r][c1][c2]=temp;
        
        
    }
    
};