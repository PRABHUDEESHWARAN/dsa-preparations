//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

//Nodes at distance K from target Node: Given a binary search tree , targetNode and distance, we need to return the nodes
//that are at a distance k from the targetNode.
// return the sorted vector of all nodes at k dist
        
        /*
        1. find the target node
        2.make the parent pointer map for each node
        3.have a dis var as 0 as move radially in all direc root,left,right each time
        and increase dis by 1.
        4.if dis equals given k then break and the elements in the queue are the nodes at k distance
        */
// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:
void findTarget(Node* root,Node* &targetNode,int target)
{
    //do in order traversal and find target node.
    Node* curr=root;
    if(curr->data==target)
    {
        targetNode=curr;
        return;
    }
    if(curr==NULL)
    {
        return;
    }
    if(curr->left)
    {
        findTarget(curr->left,targetNode,target);
    }
    if(curr->right)
    {
        findTarget(curr->right,targetNode,target);
    }
    
    
}
void fillParent(Node* root,unordered_map<Node*,Node*> &parent)
{
    Node* curr=root;
    //init queue and push root node.
    queue<Node*> q;
    q.push(curr);
    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();
        if(temp->left)
        {
            parent[temp->left]=temp;
            q.push(temp->left);
        }
        if(temp->right)
        {
            parent[temp->right]=temp;
            q.push(temp->right);
        }
    }
}

public:

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        
        
        vector<int> ans;
        Node* targetNode;
        findTarget(root,targetNode,target);
        
        unordered_map<Node*,Node*> parent;
        fillParent(root,parent);
        // cout<<parent[root->left]->data<<" ";
        
        int dis=0;
        
        queue<Node*>q;
        //visited map.
        unordered_map<Node*,int>visited;
        q.push(targetNode);
        //visit root.
        visited[targetNode]=1;
        
        while(!q.empty())
        {
            //base condition
            if(dis==k)
            {
                break; 
            }else dis++;
            
            
            int n=q.size();
            //each time going for all elements in the queue.
            for(int i=0;i<n;i++)
            {
                
                Node* curr=q.front();
                Node* parentNode=parent[curr];
                q.pop();
                if(curr->left && !visited[curr->left])
                {
                    visited[curr->left]=1;
                    q.push(curr->left);
                }
                
                if(curr->right && !visited[curr->right])
                {
                    visited[curr->right]=1;
                    q.push(curr->right);
                }
                if(parent[curr] && !visited[parent[curr]])
                {
                    visited[parent[curr]]=1;
                    q.push(parent[curr]);
                }
            }
            
        }
        
        //store answers
        while(!q.empty())
        {
            ans.push_back(q.front()->data);
            q.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends