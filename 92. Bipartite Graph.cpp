class Solution {
public:
bool isBipartite(vector<vector<int> >& graph) {
        vector<int> colors(graph.size(),0);
        vector<bool> visited(graph.size(),false);
        int color=1;
        for(int i=0; i<graph.size(); i++)
                if(colors[i]==0)
                        if(!can_color(i,colors,color,graph))
                                return false;

        return true;
}
bool can_color(int current_node,vector<int>&colors,int color, vector<vector<int> >&graph)
{
        if(colors[current_node]!=0)
                return colors[current_node]==color;


        colors[current_node]=color;
        for(int i=0; i<graph[current_node].size(); i++)
                if(!can_color(graph[current_node][i],colors,-color,graph))
                        return false;

        return true;
}
};
