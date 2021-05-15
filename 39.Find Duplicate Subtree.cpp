//Question No.652
// Given the root of a binary tree, return all duplicate subtrees.
// For each kind of duplicate subtrees, you only need to return the root node of any one of them.
// Two trees are duplicate if they have the same structure with the same node values.



class Solution {
public:
string serialize(TreeNode* root, unordered_map<string,int>& mp, vector<TreeNode*>& result)
{
        if(!root)
                return "";
        string s=to_string(root->val)+","+serialize(root->left,mp, result)+","+serialize(root->right,mp,result);
        if(++mp[s]==2)
                result.push_back(root);
        return s;
}
vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int>mp;
        vector<TreeNode*>result;
        serialize(root,mp, result);
        return result;
}
};
