class Solution {
    public:
        int longestChain = INT_MIN;
            vector<bool> visited;
        int longestStrChain(vector<string>& words) {
            vector<vector<string>> graph(18);
            visited.resize(18,false);
            for(auto &word:words)
                graph[word.size()].push_back(word);
            
            for(int i=1;i<=17;i++){
                // maxPossible from here is 17-i,
                if(visited[i]==false){
                    cout<<"Starting from "<<i<<endl;
                    helper(i,"",0,graph);
                }
                    
            }
            return longestChain;
        }
    
        void helper(int rowNumber,string currentWord, int chainLen, vector<vector<string>> &graph){
            longestChain = max(longestChain,chainLen);
            visited[rowNumber]=true;
            cout<<" rowNumber "<<rowNumber<<" Covered "<<endl;
            for(int i=0;i<graph[rowNumber].size();i++){
                if(currentWord=="" || isPossible(currentWord,graph[rowNumber][i])){
                    helper(rowNumber+1,graph[rowNumber][i],chainLen+1,graph);
                }
            }
            return ;
        }
    
        bool isPossible(string &start, string &target){
    
            int count=0,p1=0,p2=0;
            while(p1<start.size() && p2<target.size()){
                if(start[p1]!=target[p2]){
                    count++;
                    p2++;
                }else{
                    p1++;
                    p2++;
                }
                if(count==2)
                    return false;
            }
            return true;
        }
    };
    