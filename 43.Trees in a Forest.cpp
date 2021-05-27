//Ques No. 1110
// Given the root of a binary tree, each node in the tree has a distinct value.
// After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).
// Return the roots of the trees in the remaining forest. You may return the result in any order.
// Run complexity --> O(n)  Space complexity --> O(n)
class Solution {
public:
vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<int,int> umap;
        vector<TreeNode*> res;
        for(auto i:to_delete)
                umap[i]++;
        traverse(root,umap,res);
        if(!umap[root->val])
                res.push_back(root);
        return res;

}
TreeNode* traverse(TreeNode*&root,unordered_map<int,int> &umap,vector<TreeNode*> &res)
{
        if(root!=NULL) {
                root->left= traverse(root->left,umap,res);
                root->right= traverse(root->right,umap,res);
                if(umap[root->val])
                {

                        if(root->left)
                                res.push_back(root->left);
                        if(root->right)
                                res.push_back(root->right);

                        return NULL;
                }
                else
                        return root;
        }
        return NULL;
}
};
