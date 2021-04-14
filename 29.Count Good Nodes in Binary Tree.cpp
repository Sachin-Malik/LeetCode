// Given a binary tree root, a node X in the tree is named good if in the path
//from root to X there are no nodes with a value greater than X.

// Return the number of good nodes in the binary tree.



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
int goodNodes(TreeNode* root) {
        int goodNodes=0;
        if(root==NULL)
                return goodNodes;
        int currentMax=INT_MIN;

        findGoodNodes(root,currentMax,goodNodes);
        return goodNodes;

}
void findGoodNodes(TreeNode* root,int currentMax,int &goodNodes)
{
        if(root!=NULL)
        {
                if(root->val>currentMax)
                {
                        goodNodes++;
                        currentMax=root->val;
                }
                findGoodNodes(root->left,currentMax,goodNodes);
                findGoodNodes(root->right,currentMax,goodNodes);
        }
}
};
