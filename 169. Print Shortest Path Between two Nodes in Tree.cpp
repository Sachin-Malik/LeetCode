class Solution {
     string path="";
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        //first just find the lowest common ancester Node.
        TreeNode* lca=getLowestCommonAncester(root,startValue,destValue);

        //After findind LCA find both nodes separately down from LCA
        string startPath="",destPath="";
        findNode(lca,startValue,startPath);
        startPath=path;
        path="";
        findNode(lca,destValue,destPath);
        destPath=path;

        //if any of length ==0 that means we don't have a bend in our answer;
        if(startPath.length()==0){
           return destPath;
        }

        if(destPath.length()==0){
             string res="";
             for(int i=0;i<startPath.length();i++){
                     res.push_back('U');
             }
             return res;
        }

        //if there is a bend just convert the startPath to a string of 'U' appropriate number of times.
        string res="";
        for(int i=0;i<startPath.length();i++){
                res.push_back('U');
        }

        //and simply add the desPath to end of that.
        res+=destPath;
        return res;
      
    }
    TreeNode* getLowestCommonAncester(TreeNode* root,int l,int r){
        
        if(root==NULL){
            return  nullptr;
        }
        
        if(root->val==l||root->val==r)
            return root;
        
        TreeNode* lNode=getLowestCommonAncester(root->left,l,r);
        TreeNode* rNode=getLowestCommonAncester(root->right,l,r);
        
        if(lNode!=NULL&&rNode!=NULL){
            sameSide=false;
            return root;
        }
        
        if(lNode==NULL&&rNode==NULL)
            return NULL;
        
        if(lNode==NULL)
            return rNode;
        
        else
            return lNode;
        
        
    }
    void findNode(TreeNode* root,int &target,string &current){
        
        if(root==NULL)
            return;
        if(root->val==target){
            path=current;
            return;
        }
        current.push_back('L');
        findNode(root->left,target,current);
        current.pop_back();
        current.push_back('R');
        findNode(root->right,target,current);
        current.pop_back();
        
    }
};