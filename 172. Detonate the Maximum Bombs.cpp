class Solution {
public:

    bool inRange(vector<int>&a,vector<int>&b){
         long long centerDistance = (long long)pow(abs(a[0]-b[0]),2)+ pow(abs(a[1]-b[1]),2);
         long long radiusSum=(long long)a[2]*(long long)a[2];
         return radiusSum>=centerDistance;
    }
    
    int dfs(int index,vector<vector<int>>&bombs,vector<bool> &visited){
         if(visited[index])
             return 0;
        
        auto currentBomb=bombs[index];
        visited[index]=true;
        int count=1;
        
        for(int i=0;i<bombs.size();i++){
            if(!visited[i]&&inRange(currentBomb,bombs[i]))
              count+=dfs(i,bombs,visited);
        }
        return count;

    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size(),maxBomb=INT_MIN;
        vector<bool> visited(n,false);
        
         //start fresh from every node
        for(int i=0;i<n;i++){
            maxBomb=max(maxBomb,dfs(i,bombs,visited));
            fill(visited.begin(),visited.end(),false);
        }
        return maxBomb;
    }
};