class Solution {
public:
   
    int minFlips(vector<vector<int>>& mat) {
        int row=mat.size(),col=mat.at(0).size();
        int l=row*col;
        int minSwaps=INT_MAX,currentSwaps=0;
        vector<int> vtr(l,0);
        
        for(int i=pow(2,l)-1;i>=0;i--){

            fill(vtr.begin(),vtr.end(),0);
            currentSwaps=0;
            int temp=i,ptr=0;
            while(temp>0){
                int rem=temp%2;
                if(rem==1)
                    currentSwaps++;
                vtr[ptr]=rem;
                temp=temp/2;
                ptr++;
            }
            
            if(currentSwaps<minSwaps&&flipBitandCheck(mat,vtr)){
                minSwaps=currentSwaps;
            }
           
        }
        return minSwaps;
    }
    
    //MAP THE BITS OF VTR TO i and j AND FLIPS IF VTR[i]==1
    bool flipBitandCheck(vector<vector<int>> mat,vector<int>&vtr){
        int row=mat.size();
        int col=mat.at(0).size();
        
        int i=0;j=0;
        for(int m=0;m<vtr.size();m++){
            if(vtr[m]==1){
                flipTHis(i,j,mat);
            }
            j++;
            if(j==col){
                i++;
                j=0;
            }
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j]==1)
                return false;
            }
        }
        return true;
        
    }
    
    //FLIP CURRENT BIT AND 4 SURROUNDING BITS
    void flipThis(int i,int j,vector<vector<int>>&mat){
       
    unordered_map<int,int> mapThis;
    mapThis[0]=1;
    mapThis[1]=0;
    
       mat[i][j]=mapThis[mat[i][j]];
       if(i-1>=0){
           mat[i-1][j]=mapThis[mat[i-1][j]];
       }
       if(j-1>=0){
           mat[i][j-1]=mapThis[mat[i][j-1]];
       }
       if(i+1<mat.size()){
           mat[i+1][j]=mapThis[mat[i+1][j]];
       }
       if(j+1<mat.at(0).size()){
           mat[i][j+1]=mapThis[mat[i][j+1]];
       }

    }
    
};