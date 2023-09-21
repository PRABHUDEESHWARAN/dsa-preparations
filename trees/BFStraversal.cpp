#include<bits/stdc++.h>
using namespace std;
/*
Level order traversal in Binary Tree: Here we need to print or return the level order traversal of the given binary tree.

Intuition: The idea is to use a queue to store the nodes at each level.
-> first declare a queue and push the root into it.
->Now like bfs traversal in graph we need to take out the nodes out of the queue until the queue is empty.
-> for each node we need to take the left and right node and put it into the queue.
NOTE: The for loop ensures all elements of a level are inserted together at a time and at the end of the for loop, the will contain
nodes belonging to only one level.
we do this becoz we need the left and right child of all the nodes in the current level.
-> the current level nodes are pushed into the answer vector and when the queue is empty and loop exits
the ans is returned.
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
vector<int> levelOrder(TreeNode* root)
{
    vector<int> ans;
    //queue for bfs level order.
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* curr=q.front();
        q.pop();
        ans.push_back(curr->data);
        if(curr->left!=NULL)q.push(curr->left);
        if(curr->right!=NULL)q.push(curr->right);
    }
    return ans;
}
vector<vector<int>> levelWise(TreeNode* root)
{
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        vector<int> level;
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left!=NULL)q.push(curr->left);
            if(curr->right!=NULL)q.push(curr->right);
            level.push_back(curr->data);
        }
        ans.push_back(level);
    }

    return ans;
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

    vector<int> ans=levelOrder(root);
    for(int v:ans)
    {
        
            cout<<v<<" ";
    }
    cout<<endl;
    vector<vector<int>> ansLevelWise=levelWise(root);
    for(vector<int> v:ansLevelWise)
    {
        for(int ch:v)
        {
            cout<<ch<<" ";
        }
        cout<<endl;
    }
    return 0;
}