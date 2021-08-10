class Solution {
public:
int start_index;
unordered_map<int,int> inorder_indexes;
TreeNode* build(int left,int right,vector<int>&postorder){

        if(left>right)
                return nullptr;

        TreeNode*root=new TreeNode(postorder[start_index--]);
        int index=inorder_indexes[root->val];
        root->right=build(index+1,right,postorder);
        root->left=build(left,index-1,postorder);
        return root;
}


TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0; i<inorder.size(); i++)
                inorder_indexes[inorder[i]]=i;
        int l=0,r=inorder.size()-1;
        start_index=r;
        return build(l,r,postorder);
}
};
