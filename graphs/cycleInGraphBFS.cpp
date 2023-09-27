#include<bits/stdc++.h>
using namespace std;
/*
Detect cycles in Graph using bfs: given a graph return true if the graph contains a cycle, the graph may have multiple components.



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