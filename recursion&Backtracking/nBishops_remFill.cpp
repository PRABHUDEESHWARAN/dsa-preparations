#include <bits/stdc++.h>
/*
N bishops fill remaining:


*/
using namespace std;
void fillBishops(int row,int col,int n,int &bishops,vector<vector<int>> &v,vector<int> & delR)
{
    //check four diagonals
    int ul=0,ur=0,ll=0,lr=0;
    //upper left
    int j=col;
    for(int i=row-1;i>=0;i--)
    {   
        j--;
        if(j>=0 && v[i][j]==1)
        {
            ul=1;break;
        }
    }
    //upper right
    j=col;
    for(int i=row-1;i>=0;i--)
    {
        j++;
        if(j<n && v[i][j]==1)
        {
            ur=1;break;
        }
    }
    //lower left
    j=col;
    for(int i=row+1;i<n;i++)
    {
        j--;
        if(j>=0 && v[i][j]==1)
        {
            ll=1;break;
        }
    }
    //lower right
    j=col;
    for(int i=row+1;i<n;i++)
    {
        j++;
        if(j<n && v[i][j]==1)
        {
            lr=1;break;
        }
    }
    // cout<<ul<<ur<<ll<<lr<<endl;
    if(ul==0 && ur==0 && ll==0 && lr==0 && bishops>0 && delR[row]==0)
    {
        v[row][col]=1;
        delR[row]=1;
        bishops--;
    }
    
    return;
}
int main(int argc, char** argv)
{
int n;
cin>>n;
vector<vector<int>> v(n);
int bishops=n;
vector<int> row(n,0),col(n,0);
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        int val;
        cin>>val;
        v[i].push_back(val);
        if(val==1)
        {
            bishops--;
            row[i]=1;
        }
    }
}
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        if(v[i][j]==0)
        {
            fillBishops(i,j,n,bishops,v,row);
        }
    }
}
cout<<bishops<<endl;
// if(bishops==0)
// {
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
// }
// else cout<<"NotPossible";

}