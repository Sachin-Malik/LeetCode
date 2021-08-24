class Solution {
public:
struct TrieNode {
        struct TrieNode* left;
        struct TrieNode* right;
};
int findMaximumXOR(vector<int>& nums) {

        int n=nums.size(),max_xor_pair=INT_MIN;
        TrieNode *head=new TrieNode();
        for(int i=0; i<n; i++)
                insert_into_trie(nums[i],head);

        for(int i=0; i<n; i++) {
                int val=nums[i],current_xor=0;
                TrieNode* curr=head;
                for(int j=31; j>=0; j--) {
                        int b=(val>>j)&1;
                        if(b==0) {
                                if(curr->right) {
                                        current_xor+=pow(2,j);
                                        curr=curr->right;
                                }else{
                                        curr=curr->left;
                                }
                        }else{
                                if(curr->left) {
                                        current_xor+=pow(2,j);
                                        curr=curr->left;
                                }else
                                        curr=curr->right;
                        }
                }

                if(current_xor>max_xor_pair)
                        max_xor_pair=current_xor;
        }
        return max_xor_pair;

}

void insert_into_trie(int val,TrieNode*head){
        TrieNode *curr=head;
        for(int i=31; i>=0; i--) {
                int b=(val>>i)&1;
                if(b==0) {
                        if(curr->left==NULL) curr->left=new TrieNode();
                        curr=curr->left;
                }else{
                        if(curr->right==NULL) curr->right=new TrieNode();
                        curr=curr->right;
                }
        }
}
};
