#include<bits/stdc++.h>
using namespace std;
/*
Height of the binary Tree: Given a binary tree we need to return the maximum depth of the binary tree.
Also known as the height of the binary tree.

Intuition:
    -> here we can use the recursion or the bfs method that uses a queue data structure.
    ->the basic recursion condition would be : 1 + max(left height,right height).
*/
class TreeNode
{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int data)
        {
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
};
int height(TreeNode* root)
{
   TreeNode* curr=root;
        if(curr==NULL)return 0;
    
        int lh=height(curr->left);
        int rh=height(curr->right);
    return 1 + max(lh,rh);
}
int main()
{
    TreeNode* root=new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> right = new TreeNode(3);
    root -> left -> left = new TreeNode(4);
    root -> left -> right = new TreeNode(5);
    root -> left -> right -> left = new TreeNode(8);
    root -> right -> left = new TreeNode(6);
    root -> right -> right = new TreeNode(7);
    root -> right -> right -> left = new TreeNode(9);
    root -> right -> right -> right = new TreeNode(10);

    cout<<height(root);
    return 0;
}