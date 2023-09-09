#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    int v1=(m%2==0)?m+1:m,v2=0;
    for(int i=m;i<=n;i++)
    {
        if(i%2==0)
        {
            v2|=i;
        }
        else{
            v1=v1&i;
        }
    }
    cout<<v1<<" "<<v2;
    return 0;
}