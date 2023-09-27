#include<bits/stdc++.h>
using namespace std;
/*
Detect cycles in Graph using bfs: given a graph return true if the graph contains a cycle, the graph may have multiple components.
    -> here we are given a graph and we need to find if cycle exist in it using bfs.
    -> Therefore while doing bfs, we know that we will go level wise, and the idea is that
        -> from root node we will split into two paths in the next level 
        eg:  1      so, when we encounter a node which is already visited and it is not our parent then how can it be visited ?
            2 3      -> it is becoz another path has already visited that node by the current path reached that node therefore 
          4 5 6 7       a cycle exist in the graph.

        -> to keep track of the parent and the current node we use pair in the queue.

*/
class Solution
{
    public:
        bool detect(int src,int vis[],vector<int> adj[])
        {

            queue<pair<int,int>> q;
            q.push({-1,src});
            vis[src]=1;
            // pop from queue and check neighbouring elements.
        while(!q.empty())
        {
            pair<int,int> temp=q.front();
            q.pop();
            int parent=temp.first;
            int current=temp.second;
            for(auto it:adj[current])
            {
                if(!vis[it])
                {
                    q.push({current,it});
                    vis[it]=1;
                }
                else if(vis[it] && it!=parent)
                {
                    return true;
                }
            }
        }
        return false;

        }



        bool isCycle(int n,vector<int> adj[])
        {

            int vis[n]={0}; //visited array
            
            for(int i=0;i<n;i++)
            {
                if(!vis[i])
                if(detect(i,vis,adj))return true;
            }
            return false;
        }

};

int main() {
    
    // V = 4, E = 2
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    Solution obj;
    bool ans = obj.isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}