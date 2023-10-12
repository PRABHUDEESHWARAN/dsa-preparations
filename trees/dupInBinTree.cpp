//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
/*

Duplicate subtree in Binary tree: given a binary Tree we need to return 1 if the tree has a duplicate subtree else 0
Note: check whether they are asking to consider leaf node or not as a subtree.

1. The intuition here is to use a set and store strings formed with the nodes of tree, and when a string to be inserted is already present
in the set maintained then there is a duplicate subtree in the given tree.

2. we pass the root and a set to solve function which will return a string # if dup subtree present else it will return the string
formed as a result of the traversal.(a string that is conacatenation of the left and right tree)

3.in the solve function
        -> we initialise an empty string each time.
        -> we have the base condition as return s+$ when it is NULL
        -> we find the string lstr and rstr by calling function solve for left and right nodes.
        -> since we dont consider leaf node, for the leaf node as current node the string formed for lstr and rstr will be of length
        3 like 3$$ or 5$$ so we have condition to check for greater then 3.
        ->if str len >3 and set already contains str then we have duplicate so we return "#"

        -> THIS "#" is the indicator we have found a duplicate, so each level of backtracing should check if it receives a #, if so, it 
        should also return #.

        -> at last in the main function if we receive # then we know we had a duplicate.





*/
struct Node
{
	char data;
	struct Node *left;
	struct Node *right;

	Node(char x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

struct Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node *root = new Node(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N") {

			// Create the left child for the current Node
			currNode->left = new Node(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N") {

			// Create the right child for the current node
			currNode->right = new Node(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}


// } Driver Code Ends
/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    string solve(Node* root,unordered_set<string> &st)
    {
        string s="";
         //base case
         if(root==NULL)
         {
             return s+"$";
         }
         
         //left branch
         string lstr=solve(root->left,st);
         if(lstr=="#")return "#";
         //right branch
         string rstr=solve(root->right,st);
         if(rstr=="#")return "#";
         s=root->data+lstr+rstr;
         if(s.length()>3 && st.find(s)!=st.end())
         {
             return "#";
         }
         st.insert(s);
         return s;
        
    }
    int dupSub(Node *root) {
         // code here
         unordered_set<string> st;
         string res=solve(root,st);
         if(res=="#")return 1;
         return 0;
        
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin >> t;
	//cout << t << "\n";
	while (t--)
	{
		string treeString;
		getline(cin >> ws, treeString);
		struct Node* root = buildTree(treeString);
		Solution ob;
		cout << ob.dupSub(root) << "\n";
	}
	return 0;
}
// } Driver Code Ends