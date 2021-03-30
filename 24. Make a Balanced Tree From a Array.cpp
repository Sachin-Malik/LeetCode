
class Solution {
public:
TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* dummy= new TreeNode(0);
        TreeNode* temp;
        int l=0,r=nums.size();
        makeBalancedTree(temp,l,r,nums);
        return temp;
}
void makeBalancedTree(TreeNode* &root, int l, int r, vector<int> &nums){
        if(l<0||r>nums.size()||l>=r)
                return;
        int mid=(l+r)/2;
        root= new TreeNode(nums[mid]);
        makeBalancedTree(root->left,l,mid, nums);
        makeBalancedTree(root->right,mid+1,r,nums);
}
};
