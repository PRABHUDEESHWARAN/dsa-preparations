#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    if(b==0)
    {
        return a; 
    }

    return gcd(b,a%b);
}


int main()
{

    int n,x,count=0;
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(gcd(i,j)==x)
            {
                count++;
            }
        }
    }

    cout<<count;
    return 0;
}