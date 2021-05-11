class Solution
{
public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        bool res = false;
        traverse(root, subRoot);
        return res;
    }
    void traverse(TreeNode *root, treeNode &subRoot, bool &res)
    {
        if (res)
            return;
        if (root != NULL)
        {
            if (root->val == subRoot->val)
                res = compare(root, subRoot);
            if (res)
                return;
            traverse(root->left, subRoot);
            traverse(root->right, subRoot);
        }
    }
    bool compare(TreeNode *&root, TreeNode *&subRoot)
    {
        if (root == NULL && subRoot == NULL)
            return true;
        else if (root != NULL && subRoot != NULL && root->val == subRoot->val)
            return (compare(root->left, subRoot->left) && compare(root->right, subRoot->right));
        else
            return false;
    }
};