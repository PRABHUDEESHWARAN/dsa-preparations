#include <bits/stdc++.h>
 //put conditions separately for hollow and inner pattern.
using namespace std;

int main(int argc, char** argv)
{
int n;
cin>>n;
int flag=0;
if(n%2==0)
{
    flag=1;
}
for(int i=0;i<(n*2)-1;i++)
{
    for(int j=0;j<(n*2)-1;j++)
    {
        if(j<abs(n-i-1) || j>n+i-1 || j>((n*2)-2)-(i-n+1))
        {
            cout<<"#";
        }
        else if(i%2==flag)
        {
            if(j%2==0)
            {
                cout<<"*";
            }
            else
            {
                cout<<"-";
            }
        }
        else
        {
            if(j%2==1)
            {
                cout<<"*";
            }
            else
            {
                cout<<"-";
            }
        }
    }
    cout<<endl;
}

}