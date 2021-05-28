//979. Distribute Coins in Binary Tree
class Solution {
public:
int distributeCoins(TreeNode* root) {
        int moves=0;
        traverse(root,moves);
        return moves;
}
int  traverse(TreeNode* root,int&moves)
{
        if(root!=NULL)
        {
                int l=traverse(root->left,moves);
                int r=traverse(root->right,moves);
                moves+=abs(l)+abs(r);
                root->val=root->val+l+r;
                return root->val-1;
        }
        else return NULL;
}
};
