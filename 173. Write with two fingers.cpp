class Solution {
public:
    unordered_map<char,pair<int,int>> cordinate;
    int dp[301][27][27];
    int minimumDistance(string word) {

       //Intailization
       memset(dp,-1,sizeof(dp));
       for(int i=0;i<6;i++){
          cordinate['A'+i]={0,i};
          cordinate['G'+i]={1,i};
          cordinate['M'+i]={2,i};
          cordinate['S'+i]={3,i};
       }
          cordinate['Y']={4,0};
          cordinate['Z']={4,1};

        //edge Case
        if(word.length()<=2)
            return 0;

        //We start with finger A on first letter and finger B on a placeholder (just above 'Z' in ascii value)
        return memo(1,word,word[0],'[');
       
    }

   
    int memo(int index,string &word,char finA,char finB){
      
      //word is completed
      if(index==word.length())
        return 0;
    
      //if we have this position cached return that.
      if(dp[index][finA-65][finB-65]!=-1)
        return dp[index][finA-65][finB-65];

      int steps=INT_MAX;

      //if we move finA to currentIndex
      steps=min(steps,getDistance(finA,word[index])+memo(index+1,word,word[index],finB));

      //if we move FinB to currentIndex
      steps=min(steps,getDistance(finB,word[index])+memo(index+1,word,finA,word[index]));

      return dp[index][finA-65][finB-65]=steps;

    }

    int getDistance(char &a,char &b){
        
        // if this is the first to be move of finger B then it should cost 0
        if(a=='[')
        return 0;
        
        // else just calulate distance for the given movement
        pair<int,int> p1,p2;
        p1=cordinate[a];
        p2=cordinate[b];

        int distance=0;
        distance= abs(p1.first-p2.first)+abs(p1.second-p2.second);
        return distance;
    }
};