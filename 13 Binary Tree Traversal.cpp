//Preorder Traversal
class Solution {
public:
vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(res,root);
        return res;
}
void preorder(vector<int>& vtr,TreeNode* root)
{
        if(root!=NULL)
        {
                vtr.push_back(root->val);
                preorder(vtr,root->left);
                preorder(vtr,root->right);
        }
}
};

//Inoder Traversal
class Solution {
public:
vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(res,root);
        return res;
}
void inorder(vector<int>& vtr,TreeNode* root)
{
        if(root!=NULL)
        {
                inorder(vtr,root->left);
                vtr.push_back(root->val);
                inorder(vtr,root->right);
        }
}
};

//postorder Traversal
class Solution {
public:
vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(res,root);
        return res;
}
void postorder(vector<int>& vtr,TreeNode* root)
{
        if(root!=NULL)
        {
                postorder(vtr,root->left);
                postorder(vtr,root->right);
                vtr.push_back(root->val);
        }
}
};
