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
void helper(TreeNode* root,int val,int depth){
        if(depth==1) {
                TreeNode* leftTemp=nullptr;
                TreeNode* rightTemp=nullptr;

                if(root->left)
                        leftTemp=root->left;
                root->left= new TreeNode(val);
                if(leftTemp)
                        root->left->left=leftTemp;


                if(root->right)
                        rightTemp=root->right;
                root->right=new TreeNode(val);
                if(rightTemp)
                        root->right->right=rightTemp;
                return;
        }
        if(root->left) helper(root->left,val,depth-1);
        if(root->right) helper(root->right,val,depth-1);
        return;
}
TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1) {
                TreeNode* newRoot=new TreeNode(val);
                newRoot->left=root;
                return newRoot;
        }
        helper(root,val,depth-1);
        return root;

}
};
