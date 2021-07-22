class Solution
{
public:
//Function to find the vertical order traversal of Binary Tree.
static bool compare(pair<pair<int,int>,int>&pp1,pair<pair<int,int>,int>&pp2){
        if(pp1.first.first+pp1.first.second>pp2.first.first+pp2.first.second)
                return false;
        if(pp1.first.first+pp1.first.second<pp2.first.first+pp2.first.second)
                return true;
        if(pp1.second<pp2.second)
                return true;
        return false;
}
map<int,vector<pair<pair<int,int>,int> >,greater<int> > effective;
vector<vector<int> > res;
vector<vector<int> > verticalTraversal(TreeNode *root)
{
        if(root==NULL)
                return {};

        traverse(root,0,0);
        vector<int> r;
        vector<pair<pair<int,int>,int> > temp;
        for(auto&e:effective) {
                temp=e.second;
                sort(temp.begin(),temp.end(),compare);
                r.clear();
                for(auto &t:temp)
                        r.push_back(t.second);
                res.push_back(r);
        }
        return res;

}
void traverse(TreeNode* root,int l,int r){
        if(root!=NULL) {
                effective[l-r].push_back({{l,r},root->val});
                traverse(root->left,l+1,r);
                traverse(root->right,l,r+1);
        }
}
};
