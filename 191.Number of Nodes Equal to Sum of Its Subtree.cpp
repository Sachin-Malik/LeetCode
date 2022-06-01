class Solution {
public:
int ans=0;
int averageOfSubtree(TreeNode* root) {
        vector<int> res= helper(root);
        return ans;
}

vector<int> helper(TreeNode*root){

        if(!root)
                return {0,0};

        vector<int> leftSubtree,rightSubtree;
        if(root->left) {
                leftSubtree = helper(root->left);
        }

        if(root->right) {
                rightSubtree = helper(root->right);
        }

        vector<int> thisNode;
        int leftSum=0,rightSum=0;
        int leftNodes=0,rightNodes=0;

        if(leftSubtree.size()>=2) {
                leftNodes+=leftSubtree[0];
                leftSum+=leftSubtree[1];
        }

        if(rightSubtree.size()>=2) {
                rightNodes+=rightSubtree[0];
                rightSum+=rightSubtree[1];
        }

        int totalNodes = leftNodes+rightNodes+1;
        int totalSum = leftSum + rightSum + (int)root->val;

        int avg = (int)totalSum/(int)totalNodes;
        if(avg==root->val)
                ans++;

        return {leftNodes+rightNodes+1,leftSum+rightSum+root->val};
}
};
