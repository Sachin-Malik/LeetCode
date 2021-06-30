class Solution {
public:
int good_pairs=0;
int countPairs(TreeNode* root, int distance) {
        vector<int> res=traverse(root,distance);
        return good_pairs;
}
vector<int> traverse(TreeNode* root,int &distance)
{
        if(root!=NULL)
        {
                if(root->left==NULL&&root->right==NULL)
                {

                        return {1};
                }

                vector<int> left= traverse(root->left,distance);
                vector<int> right=traverse(root->right,distance);

                vector<int> res;
                if(left.size()==0)
                {
                        for(int i=0; i<right.size(); i++)
                                res.push_back(right[i]+1);
                        return res;
                }

                if(right.size()==0)
                {
                        for(int i=0; i<left.size(); i++)
                                res.push_back(left[i]+1);
                        return res;
                }


                for(int i=0; i<left.size(); i++)
                        for(int j=0; j<right.size(); j++)
                                if(left[i]+right[j]<=distance)
                                        good_pairs++;

                for(int i=0; i<left.size(); i++)
                        if(left[i]<distance)
                                res.push_back(left[i]+1);

                for(int i=0; i<right.size(); i++)
                        if(right[i]<distance)
                                res.push_back(right[i]+1);

                left.clear();
                right.clear();

                return res;
        }
        return {};
}
};
