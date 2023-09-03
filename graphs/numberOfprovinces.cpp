#include<bits/stdc++.h>
using namespace std;
/*
Number of provinces: Here given a graph we need to find the number of provinces of connected components in the graph.
-> we can do that by using both bfs and dfs which visits all the nodes.
-> INTUITION:
    -> let us  say the whole graph is connected, then travelling just one node will make sure the whole
    graph is traversed without leaving any node.
    ->But if the whole graph is not connected and separated into many parts, then travelling a particular node will
    make sure only the nodes in that province or subgraph is visited.
    -> therefore when travelling any selected node, after bfs of dfs traversal will definitely leave one or more 
    unvisited node.
    ->So this is what we do,
            -> we run a for loop for the nodes in the graph,
            ->we send the first node to bfs or dfs, which will mark all connected nodes(neighbours) as visited.
            -> on returning from the dfs/bfs for next iteration of the loop, we might get a node which is already visited
            or a node from the another province which is not yet been traversed.
            -> so we traverse that node and everytime we start a new province we increment the counter. which can also be said as
            everytime we get a unvisited node in the for loop we increment the counter.
*/
class Solution
{

    public:
        void dfs(int node,vector<vector<int>> adj, int vis[])
        {

            vis[node]=1;
            for(auto it:adj[node])
            {
                if(!vis[it])dfs(it,adj,vis);
            }

        }
        void bfs(int node,vector<vector<int>> adj,vector<int> &visit)
        {
            queue<int> q;
            q.push(node);
            visit[node]=1;
            while(!q.empty())
            {
                int data=q.front();
                q.pop();
                for(auto it:adj[data])
                {
                    if(!visit[it])
                    {
                    visit[it]=1;
                    q.push(it);
                    }
                        
                }
            }
        }
    
        //using DFS.
        int numProvincesDFS(vector<vector<int>> adj,int V)
        {   
            int cnt=0; // for ans.
            //visited array.
            int vis[V]={0};
            for(int i=0;i<V;i++)
            {
                if(!vis[i])
                {
                    cnt++;
                    dfs(i,adj,vis);
                }
            }
            return cnt;

        }
        //using BFS.
        int numProvincesBFS(vector<vector<int>> adj,int V)
        {
            int cnt=0;
            vector<int> visit(V,0);
            for(int i=0;i<V;i++)
            {
                if(visit[i]==0)
                {
                    cnt++;
                    bfs(i,adj,visit);
                }
            }
            return cnt;
        }



};
int main() {
    
    vector<vector<int>> adj
    {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

        
    Solution ob;
    cout << ob.numProvincesDFS(adj,3) << endl;
    cout << ob.numProvincesBFS(adj,3) << endl;


        
    return 0;
}
