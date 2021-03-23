/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
bool isValidBST(TreeNode* root) {
        if(root==NULL)
                return true;
        long long l= -1e10;
        long long h=1e10;
        return checkBST(root,l,h);
}
bool checkBST(TreeNode* root, long long l, long long h)
{
        if(root==NULL)
                return true;
        return (root->val>l && root->val < h) && checkBST(root->left, l, root->val)
               && checkBST(root->right,root->val,h);
}
};


//NOTE* Nice way to implement the
