#include<bits/stdc++.h>
using namespace std;
/*
Binary tree traversal: given a binary tree we can perform dfs traversals in three of the following ways,
    -> Preorder -> root,left,right
    -> inorder -> left,root,right
    ->postorder -> left,right,root
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
void order(TreeNode *root,vector<int> &ans,int type)
{
    if(root==NULL)
    {
        return;
    }
    switch(type)
    {
        case 1:
            order(root->left,ans,1);
            ans.push_back(root->data);
            order(root->right,ans,1);
            return;
        case 2:
            ans.push_back(root->data);
            order(root->left,ans,2);
            order(root->right,ans,2);
            return;
        case 3:
            order(root->left,ans,3);
            order(root->right,ans,3);
            ans.push_back(root->data);
            return;
    }
}

vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<int>ans;
    vector<vector<int>> res;
    order(root,ans,1);
    res.push_back(ans);
    ans.clear();
    order(root,ans,2);
    res.push_back(ans);
    ans.clear();
    order(root,ans,3);
    res.push_back(ans);
    return res;
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

    vector<vector<int>> ans=getTreeTraversal(root);
    for(vector<int> v:ans)
    {
        for(int ch:v)
        {
            cout<<ch<<" ";
        }
        cout<<endl;
    }
    return 0;
}