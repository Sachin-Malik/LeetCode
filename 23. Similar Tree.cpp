class Solution {
public:
bool isSymmetric(TreeNode* root)
{
        if(root==NULL)
                return true;
        return checkBST(root->left,root->right);
}
bool checkBST(TreeNode*l,TreeNode*r){
        if(l==NULL&&r==NULL)
                return true;
        if(r!=NULL&&l!=NULL)
        {
                if(r->val==l->val)
                        return checkBST(l->left,r->right)&&checkBST(l->right,r->left);
                else
                        return false;
        }
        else return false;
}
};
