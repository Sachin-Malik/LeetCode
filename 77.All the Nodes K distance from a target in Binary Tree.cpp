
class Solution {
public:
vector<int> res;
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        int level=0;
        find_target(root,target,k,level);
        return res;
}
int find_target(TreeNode* root,TreeNode* target,int &k,int level)
{
        if(root!=nullptr)
        {
                int l =find_target(root->left,target,k,level);
                int r = find_target(root->right,target,k,level);
                if(l!=0) {
                        if(l<k) {
                                down_nodes(root->right,k-l,1);
                                return l+1;
                        }
                        else if(l==k)
                        {
                                res.push_back(root->val);
                                return l+1;
                        }
                        else
                                return 0;
                }
                if(r!=0)
                {
                        if(r<k) {
                                down_nodes(root->left,k-r,1);
                                return r+1;
                        }
                        if(r==k) {
                                res.push_back(root->val);
                                return r+1;
                        }
                        else
                                return 0;

                }
                if(root==target)
                {
                        down_nodes(root,k,0);
                        return 1;
                }
                return 0;
        }
        return 0;
}
void down_nodes(TreeNode* root,int k,int level)
{
        if(root!=NULL)
        {
                if(level==k)
                {
                        res.push_back(root->val);
                        return;
                }
                down_nodes(root->left,k,level+1);
                down_nodes(root->right,k,level+1);
        }
}
};
