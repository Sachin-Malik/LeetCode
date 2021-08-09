class Solution {
public:
bool pyramidTransition(string bottom, vector<string>& allowed) {
        string result="",current="";
        return bfs(0,bottom,current,allowed);
}
bool bfs(int index,string &bottom,string intial,vector<string>&allowed){

        if(bottom.length()==1)
                return true;

        if(index+1==bottom.length())
                return bfs(0,intial,"",allowed);

        string current="";
        current+=bottom[index];
        current+=bottom[index+1];
        for(int i=0; i<allowed.size(); i++) {
                if(current==allowed[i].substr(0,2)) {
                        intial+=allowed[i][2];
                        if(bfs(index+1,bottom,intial,allowed))
                                return true;
                        intial.pop_back();
                }
        }
        return false;
}
};
