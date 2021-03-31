class Solution
{
int preorderIndex = 0;
unordered_map<int,int> inorderIndexMap;
TreeNode* build(int start, int end, vector<int> &preorder, vector<int> &inorder){
        if(start>end) return nullptr;
        TreeNode* node = new TreeNode(preorder[preorderIndex++]);
        int index = inorderIndexMap[node->val];
        node->left = build(start,index-1,preorder,inorder);
        node->right = build(index+1,end,preorder,inorder);
        return node;
}
public:
TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder) {
        for(int i = 0; i < inorder.size(); ++i)
                inorderIndexMap[inorder[i]] = i;
        return build(0,inorder.size()-1,preorder,inorder);
}
};
