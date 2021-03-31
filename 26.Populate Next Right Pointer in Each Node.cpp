// Ques: You are given a perfect binary tree where all leaves are on the same level,
// and every parent has two children. The binary tree has the following definition:
//

/*
   // Definition for a Node.
   class Node {
   public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
   };
 */

class Solution {
public:
Node* connect(Node* root) {
        if(root==NULL)
                return root;
        populateRight(root);
        return root;
}
void populateRight(Node* root)
{
        queue<Node*> q;
        q.push(root);
        Node* current;
        int size;
        while(q.size()!=0)
        {
                size=q.size();
                for(int i=0; i<size; i++)
                {
                        current=q.front();
                        q.pop();
                        if(i!=size-1)
                                current->next=q.front();
                        if(current->left!=NULL)
                                q.push(current->left);
                        if(current->right!=NULL)
                                q.push(current->right);
                }
        }
}
};
