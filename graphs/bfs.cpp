#include<bits/stdc++.h>
using namespace std;
/*
breadth first search:
    ->Given an undirected/directed graph, we need to print the breadth first traversal of the graph.
    -> Using the adjacency list we traverse the next level neighbours of the current node.
    ->we visit the only neighbours that are unvisited, we do this by maintaining a visited array.
*/

class Solution
{

    public:
        vector<int> bfsOfGraph(int V,vector<int> adj[])
        {
            
            vector<int> ans;//init basic components that are needed for the traversal.
            int vis[V]={0};
            vis[0]=1;
            queue<int> q;
            q.push(0);
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                ans.push_back(node);
                for(auto it: adj[node])
                {
                    if(!vis[it])
                    {
                        vis[it]=1;
                        q.push(it);
                    }
                }
            }
            return ans;
        }
};


void printAns(vector<int> v)
{
    for(auto it:v)
    {
        cout<<it<<" ";
    }
    return;
}



















// func for adding edge.
void addEdge(vector<int> adj[],int v,int u)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
    return;
}


int main() 
{
    vector <int> adj[6];
    
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    Solution obj;
    vector <int> ans = obj.bfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}