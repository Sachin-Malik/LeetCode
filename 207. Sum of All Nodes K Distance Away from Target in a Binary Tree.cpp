
class Solution {
public:
    vector<int> result;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        traverse(root,target,k);
        return result;
    }

    int traverse(TreeNode* root, TreeNode* target, int k){
        if(!root) return -1;
        if(root==target){
            getSumOfDepth(root,k);
            return 1;
        }
        else{
            int foundInLeft = traverse(root->left,target,k);
            int foundInRight = traverse(root->right,target,k);
            if(foundInLeft!=-1 && foundInLeft<=k){
                if(foundInLeft==k) result.push_back(root->val);
                else getSumOfDepth(root->right,k-foundInLeft-1);
                return foundInLeft+1;
            }
            if(foundInRight!=-1 && foundInRight<=k){
                if(foundInRight==k) result.push_back(root->val);
                else getSumOfDepth(root->left,k-foundInRight-1);
                return foundInRight+1;
            }
            return -1;
        }
    }

    void getSumOfDepth(TreeNode* root, int depth){
        if(!root || depth <0) return;
        if(depth==0){
            result.push_back(root->val);
            return;
        }
        getSumOfDepth(root->left,depth-1);
        getSumOfDepth(root->right,depth-1);
    }
};