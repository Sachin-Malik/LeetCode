class Solution {
public:
int totalSum=0;
int sum_at_distK(Node* root, int target, int k)
{

        int s=findTarget(root,target,k);
        return totalSum;

}
int findTarget(Node*root,int target,int &k){

        if(root==NULL)
                return -1;

        if(root->data==target) {
                sumOfSubTree(root,k);
                return 0;
        }

        int dl=findTarget(root->left,target,k);
        if(dl!=-1) {
                if(dl+1<=k)
                        totalSum+=root->data;
                sumOfSubTree(root->right,k-dl-2);
                return 1+dl;
        }

        int dr=findTarget(root->right,target,k);
        if(dr!=-1) {
                if(dr+1<=k)
                        totalSum+=root->data;
                sumOfSubTree(root->left,k-dr-2);
                return 1+dr;
        }

        return -1;
}
void sumOfSubTree(Node*root,int k){
        if(k<0||root==NULL)
                return;

        totalSum+=root->data;
        sumOfSubTree(root->left,k-1);
        sumOfSubTree(root->right,k-1);
        return;
}
};
