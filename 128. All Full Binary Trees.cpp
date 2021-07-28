vector<TreeNode*> allPossibleFBT(int n) {
        // base cases
        if(n % 2 == 0) return {};
        if(n == 1) return {new TreeNode()};

        vector<TreeNode*> res;
        for(int i = 1; i <= n - 2; i+=2) {
                vector<TreeNode*> _left = allPossibleFBT(i);
                vector<TreeNode*> _right = allPossibleFBT(n - 1 - i);

                for(auto left : _left)
                        for(auto right : _right) {
                                TreeNode *root = new TreeNode();
                                root->left = left;
                                root->right = right;
                                res.push_back(root);
                        }
        }
        return res;
}
