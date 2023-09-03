#include<bits/stdc++.h>
using namespace std;
/*
Depth first Search: given a graph perform a depth first search and return the order of traversal of the nodes.
-> In dfs for a given starting node, we select one of the neighbours of the node and we travel to the atmost depth
 starting from that node and we backtrack... Then we go on to the next neighbour of the node.
 NOTE: A node will be traversed only if its unvisited. 


 GRAPH REPRESENTATION: 
            -> it is represented using the adjacency list.
            ->we use a visited node array to maintain the list of visited node.
*/

class Solution
{
    private:
        void dfs(int node,vector<int> adj[],int vis[],vector<int> &ls)
        {

            vis[node]=1;
            ls.push_back(node);
            for(auto it:adj[node])
            {
                if(!vis[it])
                {
                    dfs(it,adj,vis,ls);
                }   
            }
        }
    public:
        vector<int> dfsOfGraph(int n,vector<int> adj[])
        {
            //visited array.
            int vis[n]={0};
            int start=0; //starting node.

            vector<int> ls; // traversal answer list.
            
            //call depth first search.
            dfs(start,adj,vis,ls);

            
            

            return ls;
        }


};


void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
    return;
}

int main() 
{
    vector <int> adj[5];
    
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);

    Solution obj;
    vector <int> ans = obj.dfsOfGraph(5, adj);
    for(int ch:ans)
    {
        cout<<ch<<" ";
    }

    return 0;
}